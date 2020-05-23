#include <bits/stdc++.h>

#define INFTY 1000000000

typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;

std::vector<std::vector<int>> G;

int **dist;
int **dp;

void dfs(int n, int d, int p, int s){
	if(dist[s][n]<d) return;
	dist[s][n]=d;
	for(auto it=G[n].begin();it!=G[n].end();it++){
		if(*it==p) continue;
		dfs(*it, d+1, n, s);
	}
}

int pianifica(int N, int M, int P1, int D1, int P2, int D2, int A[], int B[]){
	G.resize(N);
	for(int i=0;i<M;i++){
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	dist=new int*[N];
	dp=new int*[N];
	for(int i=0;i<N;i++){
		dist[i]=new int[N];
		dp[i]=new int[N];
		for(int j=0;j<N;j++){
			dist[i][j]=INFTY;
			dp[i][j]=0;
		}
	}

	// populate dist[][]: N^2
	for(int i=0;i<N;i++)
		dfs(i, 0, -1, i);

	// dp with priority_queue: N^2logN
	std::priority_queue<iii> Q;
	Q.push({dist[P1][P2], {P1, P2}});
	while(!Q.empty()){
		int p1=Q.top().second.first;
		int p2=Q.top().second.second;
		int d=Q.top().first;
		Q.pop();
		if(dp[p1][p2]>=d) continue;
		dp[p1][p2]=d;
		std::cout<<p1<<" "<<p2<<" -> "<<d<<"\n";
		if(p1==D1 && p2==D2) break;
		// move 1
		for(auto it=G[p1].begin();it!=G[p1].end();it++){
			int newd=std::min(d, dist[*it][p2]);
			if(dp[*it][p2]<newd)
				Q.push({newd, {*it, p2}});
		}
		// move 2
		for(auto it=G[p2].begin();it!=G[p2].end();it++){
			int newd=std::min(d, dist[p1][*it]);
			if(dp[p1][*it]<newd)
				Q.push({newd, {p1, *it}});
		}
	}
	return dp[D1][D2];
}

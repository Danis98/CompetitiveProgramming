#include <iostream>
#include <vector>
#include <queue>

#define MAXN 100000

int N, M, P;
std::vector<std::vector<int>> G, G_inv;
std::deque<int> order;
bool vis[MAXN];
double val[MAXN];

void dfs(int n, int p){
    vis[n]=true;
    for(auto it=G[n].begin();it!=G[n].end();it++)
        if(!vis[*it]) dfs(*it, n);
    order.push_front(n);
}

int main(){
    freopen("input.txt", "r", stdin);
    std::cin>>N>>M>>P;
    G.resize(N);
    G_inv.resize(N);
    int a, b;
    for(int i=0;i<M;i++){
        std::cin>>a>>b;
        G[a].push_back(b);
        G_inv[b].push_back(a);
    }

    for(int i=0;i<N;i++){
        if(vis[i]) continue;
        dfs(i, -1);
    }

    val[0]=1;

    for(int i=0;i<N;i++){
        int ind=order[i];
        if(ind==0) continue;
        val[ind]=0;
        for(auto it=G_inv[ind].begin();it!=G_inv[ind].end();it++)
            val[ind]+=val[*it]/(double)G[*it].size();
    }


    int res=N-P;
    for(int i=N-P+1;i<N;i++)
        if(val[i]>val[res]) res=i;

    std::cout<<res<<"\n";
    return 0;
}

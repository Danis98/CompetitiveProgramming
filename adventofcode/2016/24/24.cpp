#include <bits/stdc++.h>

#define INFTY 100000000

typedef std::pair<int, int> ii;

#define Q 8

int N, M;
char **grid;
int **dist;
std::vector<ii> points(Q);
std::vector<std::vector<ii>> G(Q);

int get_dist(int i, int j){
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) dist[i][j]=INFTY;
    ii start=points[i];
    ii end=points[j];
    std::queue<ii> q;
    q.push(start);
    dist[start.first][start.second]=0;
    while(!q.empty()){
        ii n=q.front();
        q.pop();
        if(n==end) break;
        int r=n.first, c=n.second;
        if(r>0 && grid[r-1][c]=='.' && dist[r-1][c]>dist[r][c]+1){
            dist[r-1][c]=dist[r][c]+1;
            q.push({r-1, c});
        }
        if(c>0 && grid[r][c-1]=='.' && dist[r][c-1]>dist[r][c]+1){
            dist[r][c-1]=dist[r][c]+1;
            q.push({r, c-1});
        }
        if(r<N-1 && grid[r+1][c]=='.' && dist[r+1][c]>dist[r][c]+1){
            dist[r+1][c]=dist[r][c]+1;
            q.push({r+1, c});
        }
        if(c<M-1 && grid[r][c+1]=='.' && dist[r][c+1]>dist[r][c]+1){
            dist[r][c+1]=dist[r][c]+1;
            q.push({r, c+1});
        }
    }
    return dist[end.first][end.second];
}

bool vis[Q];
int minp=INFTY;

std::vector<int> path;

void dfs(int n, int p, int d, int l){
    if(vis[n]) return;
    vis[n]=true;
    path.push_back(n);
    if(l==Q){
        minp=std::min(d, minp);
        /*for(int i=0;i<Q;i++)
            std::cout<<path[i]<<" ";
        std::cout<<": "<<d<<"\n";*/
        path.pop_back();
        vis[n]=false;
        return;
    }
    for(int i=1;i<G[n].size();i++){
        if(G[n][i].first==p) continue;
        dfs(G[n][i].first, n, d+G[n][i].second, l+1);
    }
    path.pop_back();
    vis[n]=false;
}

int main(){
    freopen("input.txt", "r", stdin);

    std::cin>>N>>M;
    grid=new char*[N];
    dist=new int*[N];
    for(int i=0;i<Q;i++)
        vis[i]=false;
    for(int i=0;i<N;i++){
        grid[i]=new char[M];
        dist[i]=new int[M];
        for(int j=0;j<M;j++){
            dist[i][j]=INFTY;
            char ch;
            std::cin>>ch;
            if(ch>='0' && ch<='9'){
                points[ch-'0']={i, j};
                grid[i][j]='.';
            }
            else
                grid[i][j]=ch;
        }
    }

    for(int i=0;i<Q;i++){
        for(int j=i+1;j<Q;j++){
            int d=get_dist(i, j);
            G[i].push_back({j, d});
            G[j].push_back({i, d});
        }
    }

    std::cout<<"GRAPH GENERATED!\n";
    for(int i=0;i<Q;i++){
        std::cout<<i<<": ";
        for(int j=0;j<G[i].size();j++)
            std::cout<<"("<<G[i][j].first<<","<<G[i][j].second<<") ";
        std::cout<<"\n";
    }

    dfs(0, -1, 0, 1);
    std::cout<<"min_path="<<minp<<"\n";
}

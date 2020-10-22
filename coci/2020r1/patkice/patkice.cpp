#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<ll2, ll2> ll4;
typedef std::pair<double, double> dd;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define _E 0
#define _N 1
#define _S 2
#define _W 3

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M;
    std::cin>>N>>M;
    std::vector<std::string> grid(N);
    for(int i=0;i<N;i++) std::cin>>grid[i];

    std::vector<std::vector<ll2>> dist(N, std::vector<ll2>(M, {-1, N*M+1}));
    ll2 start = {0, 0}, end = {0, 0};
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(grid[i][j] == 'o') start = {i, j};
            else if(grid[i][j] == 'x') end = {i, j};
    dist[start.fi][start.se] = {-1, 0};

    std::queue<ll4> Q;
    Q.push({{_N, 1}, {start.fi-1, start.se}});
    Q.push({{_W, 1}, {start.fi, start.se-1}});
    Q.push({{_S, 1}, {start.fi+1, start.se}});
    Q.push({{_E, 1}, {start.fi, start.se+1}});

    while(!Q.empty()){
        ll4 cur = Q.front();
        Q.pop();
        ll orig = cur.fi.fi;
        ll d = cur.fi.se;
        ll2 pos = cur.se;

        if(dist[pos.fi][pos.se].se < d) continue;
        else if(dist[pos.fi][pos.se].se == d && dist[pos.fi][pos.se].fi < orig)
            continue;
        dist[pos.fi][pos.se] = {orig, d};

        if(grid[pos.fi][pos.se] == '<')
            Q.push({{orig, d+1}, {pos.fi, pos.se-1}});
        if(grid[pos.fi][pos.se] == '^')
            Q.push({{orig, d+1}, {pos.fi-1, pos.se}});
        if(grid[pos.fi][pos.se] == 'v')
            Q.push({{orig, d+1}, {pos.fi+1, pos.se}});
        if(grid[pos.fi][pos.se] == '>')
            Q.push({{orig, d+1}, {pos.fi, pos.se+1}});
    }
    if(dist[end.fi][end.se].fi == -1) std::cout<<":(\n";
    else{
        std::cout<<":)\n"<<"ENSW"[dist[end.fi][end.se].fi]<<"\n";
    }

    // for(int i=0;i<N;i++)
    //     for(int j=0;j<M;j++)
    //         std::cout<<dist[i][j].se<<"\t\n"[j==M-1];
    // for(int i=0;i<N;i++)
    //     for(int j=0;j<M;j++)
    //         std::cout<<dist[i][j].fi<<"\t\n"[j==M-1];
}

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int N, M;
std::vector<std::string> col, dir;
std::vector<std::vector<bool>> done, vis;
std::vector<std::vector<int>> dist, num, cyc_id, cyc_len;
int cyc_ctr = 0;
std::map<char, ii> d;
int robots, black;

void explore(ii n, int dst){
    vis[n.fi][n.se] = true;
    ii where = d[dir[n.fi][n.se]];
    ii nxt = {n.fi+where.fi, n.se+where.se};
    dist[n.fi][n.se] = dst;

    if(done[nxt.fi][nxt.se]){
        cyc_id[n.fi][n.se] = cyc_id[nxt.fi][nxt.se];
        cyc_len[n.fi][n.se] = cyc_len[nxt.fi][nxt.se];
        int clen = cyc_len[n.fi][n.se];
        num[n.fi][n.se] = (num[nxt.fi][nxt.se]+clen-1)%clen;
        done[n.fi][n.se] = true;
        return;
    }

    if(vis[nxt.fi][nxt.se]){
        cyc_id[n.fi][n.se] = cyc_ctr++;
        cyc_len[n.fi][n.se] = dist[n.fi][n.se]-dist[nxt.fi][nxt.se]+1;
        num[n.fi][n.se] = cyc_len[n.fi][n.se]-1;
        done[n.fi][n.se] = true;
        robots += cyc_len[n.fi][n.se];
        return;
    }

    explore(nxt, dst+1);
    cyc_id[n.fi][n.se] = cyc_id[nxt.fi][nxt.se];
    cyc_len[n.fi][n.se] = cyc_len[nxt.fi][nxt.se];
    int clen = cyc_len[n.fi][n.se];
    num[n.fi][n.se] = (num[nxt.fi][nxt.se]+clen-1)%clen;
    done[n.fi][n.se] = true;
    return;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        std::cin>>N>>M;
        col.resize(N);
        dir.resize(N);
        cyc_ctr = 0;
        for(int i=0;i<N;i++) std::cin>>col[i];
        for(int i=0;i<N;i++) std::cin>>dir[i];

        d['U'] = {-1, 0};
        d['L'] = {0, -1};
        d['D'] = {1, 0};
        d['R'] = {0, 1};

        done.assign(N, std::vector<bool>(M, false));
        vis.assign(N, std::vector<bool>(M, false));
        dist.assign(N, std::vector<int>(M, -1));
        num.assign(N, std::vector<int>(M, -1));
        cyc_id.assign(N, std::vector<int>(M, -1));
        cyc_len.assign(N, std::vector<int>(M, -1));
        robots = black = 0;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(!done[i][j])
                    explore({i, j}, 0);
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++)
        //         std::cout<<cyc_id[i][j]<<" ";
        //     std::cout<<"\n";
        // }
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++)
        //         std::cout<<num[i][j]<<" ";
        //     std::cout<<"\n";
        // }
        std::vector<std::unordered_set<int>> blacks(cyc_ctr);
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(col[i][j] == '0')
                    blacks[cyc_id[i][j]].insert(num[i][j]);
        for(int i=0;i<cyc_ctr;i++) black += blacks[i].size();
        std::cout<<robots<<" "<<black<<"\n";
    }
}

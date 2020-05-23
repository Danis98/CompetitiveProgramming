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

ll N, M, Q;
std::vector<std::string> grid;
std::vector<std::vector<ll3>> closest;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N>>M>>Q;
    grid.resize(N);
    for(int i=0;i<N;i++) std::cin>>grid[i];

    closest.assign(N, std::vector<ll3>(M, {-1, {0, 0}}));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(i > 0 && grid[i-1][j] == grid[i][j]
                || i < N-1 && grid[i+1][j] == grid[i][j]
                || j > 0 && grid[i][j-1] == grid[i][j]
                || j < M-1 && grid[i][j+1] == grid[i][j]){
                closest[i][j] = {0, {i, j}};
            }
        }
    }

    std::queue<ll2> Queue;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(closest[i][j].fi == 0)
                Queue.push({i, j});
    while(!Queue.empty()){
        ll2 n = Queue.front();
        Queue.pop();
        ll i = n.fi;
        ll j = n.se;
        if(i > 0 && closest[i-1][j].fi == -1){
            closest[i-1][j] = closest[i][j];
            closest[i-1][j].fi++;
            Queue.push({i-1, j});
        }
        if(i < N-1 && closest[i+1][j].fi == -1){
            closest[i+1][j] = closest[i][j];
            closest[i+1][j].fi++;
            Queue.push({i+1, j});
        }
        if(j > 0 && closest[i][j-1].fi == -1){
            closest[i][j-1] = closest[i][j];
            closest[i][j-1].fi++;
            Queue.push({i, j-1});
        }
        if(j < M-1 && closest[i][j+1].fi == -1){
            closest[i][j+1] = closest[i][j];
            closest[i][j+1].fi++;
            Queue.push({i, j+1});
        }
    }

    // for(int i=0;i<N;i++)
    //     for(int j=0;j<M;j++)
    //         std::cout<<closest[i][j].fi<<" \n"[j==M-1];

    for(int i=0;i<Q;i++){
        ll r, c, t;
        std::cin>>r>>c>>t;
        r--;
        c--;
        ll3 clos = closest[r][c];
        ll dist = clos.fi;
        ll2 grp_pos = clos.se;
        if(dist == -1 || dist >= t)
            std::cout<<grid[r][c]<<"\n";
        else{
            int col = grid[grp_pos.fi][grp_pos.se] - '0';
            col ^= t % 2;
            std::cout<<col<<"\n";
        }
    }
}

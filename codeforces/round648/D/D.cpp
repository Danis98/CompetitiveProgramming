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

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        ll N, M;
        std::cin>>N>>M;
        std::vector<std::string> grid(N);
        for(int i=0;i<N;i++) std::cin>>grid[i];
        std::vector<ll2> to_block, target;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(grid[i][j] == 'B') to_block.pb({i, j});
                else if(grid[i][j] == 'G') target.pb({i, j});
        for(ll2 p : to_block){
            ll i = p.fi, j = p.se;
            if(i > 0) grid[i-1][j] = '#';
            if(i < N-1) grid[i+1][j] = '#';
            if(j > 0) grid[i][j-1] = '#';
            if(j < M-1) grid[i][j+1] = '#';
        }
        std::vector<std::vector<bool>> fill(N, std::vector<bool>(M, false));
        std::queue<ll2> Q;
        if(grid[N-1][M-1] != '#'){
            Q.push({N-1, M-1});
            fill[N-1][M-1] = true;
        }
        while(!Q.empty()){
            ll2 cur = Q.front();
            Q.pop();
            ll i = cur.fi, j = cur.se;
            if(i > 0 && grid[i-1][j] != '#' && !fill[i-1][j]){
                Q.push({i-1, j});
                fill[i-1][j] = true;
            }
            if(i < N-1 && grid[i+1][j] != '#' && !fill[i+1][j]){
                Q.push({i+1, j});
                fill[i+1][j] = true;
            }
            if(j > 0 && grid[i][j-1] != '#' && !fill[i][j-1]){
                Q.push({i, j-1});
                fill[i][j-1] = true;
            }
            if(j < M-1 && grid[i][j+1] != '#' && !fill[i][j+1]){
                Q.push({i, j+1});
                fill[i][j+1] = true;
            }
        }

        // for(int i=0;i<N;i++)
        //     for(int j=0;j<M;j++)
        //         std::cout<<fill[i][j]<<" \n"[j==M-1];
        // for(int i=0;i<N;i++)
        //     std::cout<<grid[i]<<"\n";

        bool good = true;
        for(ll2 p : target)
            good &= fill[p.fi][p.se];
        if(good) std::cout<<"Yes\n";
        else std::cout<<"No\n";
    }
}

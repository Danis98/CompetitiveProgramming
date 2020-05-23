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
std::vector<std::string> grid;
std::vector<std::vector<bool>> vis;

void dfs(ll2 n){
    if(vis[n.fi][n.se]) return;
    if(grid[n.fi][n.se] == '.') return;
    vis[n.fi][n.se] = true;
    if(n.fi > 0) dfs({n.fi-1, n.se});
    if(n.fi < N-1) dfs({n.fi+1, n.se});
    if(n.se > 0) dfs({n.fi, n.se-1});
    if(n.se < M-1) dfs({n.fi, n.se+1});
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N>>M;
    grid.resize(N);
    vis.assign(N, std::vector<bool>(M, false));
    for(int i=0;i<N;i++) std::cin>>grid[i];

    bool valid = true;
    std::vector<bool> row_occ(N, false), col_occ(M, false);
    // check convexity
    for(int i=0;i<N;i++){
        int s = -1, e = -1;
        for(int j=0;j<M;j++){
            if(grid[i][j] == '#'){
                row_occ[i] = true;
                if(s == -1) s = i;
                if(e == -1) continue;
                else{
                    valid = false;
                    break;
                }
            }
            else if(s != -1 && e == -1) e = i;
        }
        if(!valid) break;
    }
    for(int i=0;i<M;i++){
        int s = -1, e = -1;
        for(int j=0;j<N;j++){
            if(grid[j][i] == '#'){
                col_occ[i] = true;
                if(s == -1) s = i;
                if(e == -1) continue;
                else{
                    valid = false;
                    break;
                }
            }
            else if(s != -1 && e == -1) e = i;
        }
        if(!valid) break;
    }
    // check empty rows and col
    for(int i=0;i<N;i++){
        if(row_occ[i]) continue;
        bool good = false;
        for(int j=0;j<M;j++)
            if(!col_occ[j]){
                good = true;
                break;
            }
        if(!good){
            valid = false;
            break;
        }
    }
    for(int i=0;i<M;i++){
        if(col_occ[i]) continue;
        bool good = false;
        for(int j=0;j<N;j++)
            if(!row_occ[j]){
                good = true;
                break;
            }
        if(!good){
            valid = false;
            break;
        }
    }

    if(!valid){
        std::cout<<"-1\n";
        return 0;
    }

    // count components
    int comp = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(!vis[i][j] && grid[i][j] == '#'){
                comp++;
                dfs({i, j});
            }
    std::cout<<comp<<"\n";
}

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

std::vector<std::vector<ll>> G;
std::vector<bool> vis, cur;

bool dfs(int n, int p){
    cur[n] = true;
    vis[n] = true;
    bool ret = false;
    for(ll neigh : G[n]){
        if(neigh == p) continue;
        ret |= (cur[neigh] || !vis[neigh] && dfs(neigh, n));
    }
    cur[n] = false;
    return ret;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll N, M;
    std::cin>>N>>M;
    std::vector<std::string> m(N);
    for(int i=0;i<N;i++) std::cin>>m[i];
    G.resize(N*M);
    vis.assign(N*M, false);
    cur.assign(N*M, false);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            if(i < N-1 && m[i][j] == m[i+1][j]){
                G[i*M+j].pb((i+1)*M+j);
                G[(i+1)*M+j].pb(i*M+j);
            }
            if(j < M-1 && m[i][j] == m[i][j+1]){
                G[i*M+j].pb(i*M+j+1);
                G[i*M+j+1].pb(i*M+j);
            }
        }
    for(int i=0;i<N*M;i++){
        if(vis[i]) continue;
        if(dfs(i, -1)){
            std::cout<<"Yes\n";
            return 0;
        }
    }
    std::cout<<"No\n";
}

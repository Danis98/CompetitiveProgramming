#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int N, M, K;
std::vector<bool> vis;
std::vector<ll> sat;
std::vector<std::vector<ll>> G;
ll res = 0;

// void dfs(int n, int moves, int score){
//     if(moves < 1) return;
//     if(vis[n]) return;
//     vis[n] = true;
//     score += sat[n];
//     res = std::max(res, score);
//     for(int neigh : G[n])
//
// }

int hamming(int n){
    int r = 0;
    while(n){
        r += n & 1;
        n >>= 1;
    }
    return r;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M>>K;
    G.assign(N, std::vector<ll>(N, 0LL));
    vis.resize(N, false);
    sat.resize(N);
    for(int i=0;i<N;i++) std::cin>>sat[i];
    for(int i=0;i<K;i++){
        ll a, b, c;
        std::cin>>a>>b>>c;
        a--;
        b--;
        G[a][b] = c;
    }

    // for(int i=0;i<N;i++)
    //     dfs(i, M);

    ll NN = 1<<N;
    ll dp[NN][N];
    for(int i=0;i<NN;i++) for(int j=0;j<N;j++) dp[i][j] = 0;
    for(int i=0;i<N;i++) dp[1<<i][i] = sat[i];
    for(int i=0;i<NN;i++){
        for(int j=0;j<N;j++){
            if(((i>>j)&1) == 0) continue;
            int prev = i ^ (1<<j);
            for(int k=0;k<N;k++){
                if(((prev>>k)&1) == 0) continue;
                // std::cout<<i<<": "<<k<<"->"<<j<<" ("<<prev<<")"<<"\n";
                dp[i][j] = std::max(dp[i][j], dp[prev][k]+sat[j]+G[k][j]);
            }
            if(hamming(i) == M) res = std::max(res, dp[i][j]);
        }
    }
    std::cout<<res<<"\n";
}

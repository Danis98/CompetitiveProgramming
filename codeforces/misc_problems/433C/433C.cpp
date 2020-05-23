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

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll N, M;
    std::cin>>N>>M;
    std::vector<ll> a(M);
    std::vector<bool> pres(N+1, false);
    for(int i=0;i<M;i++){
        std::cin>>a[i];
        pres[a[i]] = true;
    }

    std::vector<std::vector<ll>> adj(N+1);
    for(int i=0;i<M;i++){
        if(i>0 && a[i-1] != a[i]) adj[a[i]].pb(a[i-1]);
        if(i<M-1 && a[i+1] != a[i]) adj[a[i]].pb(a[i+1]);
    }
    ll orig = 0, best = 0;
    for(int i=0;i<M-1;i++)
        orig += std::abs(a[i]-a[i+1]);
    best = orig;
    for(int i=1;i<=N;i++){
        if(adj[i].size() == 0) continue;
        std::nth_element(adj[i].begin(), adj[i].begin()+adj[i].size()/2, adj[i].end());
        ll median = adj[i][adj[i].size()/2];
        ll delta = 0;
        for(auto el : adj[i])
            delta += std::abs(el-median) - std::abs(el-i);
        best = std::min(best, orig + delta);
    }
    std::cout<<best<<"\n";
}

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

int N;
std::vector<std::vector<ll>> tree;
std::vector<ll> a, b, c, sub, cost, par, asub;

void dfs(int n, int p){
    sub[n] = b[n] - c[n];
    asub[n] = std::abs(sub[n]);
    if(p != -1)
        cost[n] = std::min(a[n], cost[p]);
    else cost[n] = a[n];
    par[n] = p;
    for(ll neigh : tree[n])
        if(neigh != p){
            dfs(neigh, n);
            sub[n] += sub[neigh];
            asub[n] += std::abs(sub[neigh]);
        }
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N;
    tree.assign(N, std::vector<ll>());
    a.resize(N);
    b.resize(N);
    c.resize(N);
    sub.resize(N);
    asub.resize(N);
    par.resize(N);
    cost.resize(N);
    for(int i=0;i<N;i++) std::cin>>a[i]>>b[i]>>c[i];
    for(int i=0;i<N-1;i++){
        ll x, y;
        std::cin>>x>>y;
        x--;
        y--;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    dfs(0, -1);
    if(sub[0] != 0){
        std::cout<<"-1\n";
        return 0;
    }
    ll res = 0;
    for(int i=0;i<N;i++)
        res += cost[i] * (asub[i] - std::abs(sub[i]));
    std::cout<<res<<"\n";
}

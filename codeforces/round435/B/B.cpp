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

ll N;
std::vector<std::vector<ll>> tree;
ll s[2] = {0, 0};

void dfs(int n, int p, int d){
    s[d%2]++;
    for(ll neigh : tree[n])
        if(neigh != p) dfs(neigh, n, d+1);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N;
    tree.resize(N);
    for(int i=0;i<N-1;i++){
        ll a, b;
        std::cin>>a>>b;
        a--;
        b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    dfs(0, -1, 0);

    ll res = s[0] * s[1] - N + 1;
    std::cout<<res<<"\n";
}

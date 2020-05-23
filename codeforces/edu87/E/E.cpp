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

ll N, M;
std::vector<std::vector<ll>> G;
std::vector<ll> parity;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N>>M;
    G.resize(N);
    parity.assign(N, -1);
    ll N1, N2, N3;
    std::cin>>N1>>N2>>N3;
    for(int i=0;i<M;i++){
        ll a, b;
        std::cin>>a>>b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    for(int i=0;i<N)
}

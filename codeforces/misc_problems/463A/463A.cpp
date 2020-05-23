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

    ll N, S;
    std::cin>>N>>S;
    std::vector<ll> a(N);
    S *= 100;
    ll res = -1;
    for(int i=0;i<N;i++){
        ll x, y;
        std::cin>>x>>y;
        ll p = 100*x + y;
        if(p > S) continue;
        res = std::max(res, (S - p) % 100);
    }

    std::cout<<res<<"\n";
}

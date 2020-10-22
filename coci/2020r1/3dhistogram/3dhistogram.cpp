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

    int N;
    std::cin>>N;
    std::vector<ll2> hist(N);
    for(int i=0;i<N;i++) std::cin>>hist[i].fi>>hist[i].se;
    hist.pb({0, 0});
    std::stack<int> s1, s2;
    ll vol = 0;
    for(ll2 block : hist){
        ll w = block.fi;
        ll h = block.se;
        if()
    }
}

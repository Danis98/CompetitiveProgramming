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

#define MAXA 10000

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll N, K;
    std::cin>>N>>K;
    std::vector<std::vector<ll>> h(MAXA+1);
    for(int i=0;i<N;i++){
        ll t;
        std::cin>>t;
        h[t].pb(i+1);
    }

    ll p1 = 1, p2 = MAXA, ctr = 0;
    std::vector<ll2> moves;
    while(ctr < K){
        while(h[p1].size() == 0) p1++;
        while(h[p2].size() == 0) p2--;
        if(p2 - p1 <= 1) break;
        ll high = h[p2][h[p2].size()-1];
        h[p2].pop_back();
        ll low = h[p1][h[p1].size()-1];
        h[p1].pop_back();
        moves.pb({high, low});
        h[p2-1].pb(high);
        h[p1+1].pb(low);
        ctr++;
    }
    while(h[p1].size() == 0) p1++;
    while(h[p2].size() == 0) p2--;

    std::cout<<std::max(0LL, p2-p1)<<" "<<moves.size()<<"\n";
    for(ll2 move : moves)
        std::cout<<move.fi<<" "<<move.se<<"\n";
}

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

ll minD(ll n){
    ll r = n%10;
    while(n){
        r = std::min(r, n%10);
        n /= 10;
    }
    return r;
}

ll maxD(ll n){
    ll r = 0;
    while(n){
        r = std::max(r, n%10);
        n /= 10;
    }
    return r;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll T;
    std::cin>>T;
    while(T--){
        ll A, K;
        std::cin>>A>>K;
        for(int i=2;i<=K;i++){
            ll m = minD(A);
            ll M = maxD(A);
            if(m == 0) break;
            A += m*M;
        }
        std::cout<<A<<"\n";
    }
}

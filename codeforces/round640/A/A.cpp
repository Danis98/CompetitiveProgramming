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

    int T;
    std::cin>>T;
    while(T--){
        ll N;
        std::cin>>N;
        ll mul = 1;
        std::vector<ll> res;
        while(N){
            ll d = mul * (N%10);
            if(d > 0) res.pb(d);
            mul *= 10;
            N /= 10;
        }
        std::cout<<res.size()<<"\n";
        for(ll a : res)
            std::cout<<a<<" ";
        std::cout<<"\n";
    }
}

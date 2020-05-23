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

ll f_best(ll N, ll M){
    ll a = (N-M)%(M+1);
    ll b = (N-M)/(M+1);
    return (N*(N+1))/2-(a*(b+1)*(b+2))/2-((M+1-a)*b*(b+1))/2;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        ll N, M;
        std::cin>>N>>M;
        std::cout<<f_best(N, M)<<"\n";
    }
}

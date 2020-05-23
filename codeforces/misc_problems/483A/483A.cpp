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

    ll L, R;
    std::cin>>L>>R;
    R -= R%2;
    if(R-2 < L || R-2 <= 1){
        std::cout<<"-1\n";
        return 0;
    }
    std::cout<<(R-2)<<" "<<(R-1)<<" "<<R<<"\n";
}

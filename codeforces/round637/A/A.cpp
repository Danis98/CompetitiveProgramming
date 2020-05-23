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
        ll N, A, B, C, D;
        std::cin>>N>>A>>B>>C>>D;

        ll min = N*(A-B), max = N*(A+B);
        ll l = C-D, r = C+D;
        if(max < l || min > r)
            std::cout<<"No\n";
        else
            std::cout<<"Yes\n";
    }
}

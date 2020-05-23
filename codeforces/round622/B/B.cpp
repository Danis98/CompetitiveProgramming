#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
        ll N, X, Y;
        std::cin>>N>>X>>Y;
        ll S = X + Y;
        if(X > Y) std::swap(X, Y);
        // Best case
        std::cout<<std::max(1LL, S-N)<<" ";
        // Worst case
        std::cout<<std::min(N, S-1)<<"\n";
    }
}

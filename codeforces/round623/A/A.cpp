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
        ll a, b, x, y;
        std::cin>>a>>b>>x>>y;
        ll area = 0;
        area = std::max(area, a * y);
        area = std::max(area, a * (b-y-1));
        area = std::max(area, b * x);
        area = std::max(area, b * (a-x-1));
        std::cout<<area<<"\n";
    }
}

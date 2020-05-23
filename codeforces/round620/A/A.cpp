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

    int T, x, y, a, b;
    std::cin>>T;
    for(int t=0;t<T;t++){
        std::cin>>x>>y>>a>>b;
        if((y-x) % (a+b) == 0){
            std::cout<<(y-x)/(a+b)<<"\n";
        }
        else std::cout<<"-1\n";
    }
}

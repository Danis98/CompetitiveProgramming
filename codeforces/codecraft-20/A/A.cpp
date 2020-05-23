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
        ll N, M;
        std::cin>>N>>M;
        ll s = 0;
        for(int i=0;i<N;i++){
            int t;
            std::cin>>t;
            s += t;
        }
        std::cout<<std::min(s, M)<<"\n";
    }
}

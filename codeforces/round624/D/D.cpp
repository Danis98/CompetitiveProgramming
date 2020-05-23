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
        int a, b, c;
        std::cin>>a>>b>>c;
        int min_cost = a+b+c-3;
        int min_a = a, min_b = b, min_c = c;
        for(int i=1;i<=10000;i++)
            for(int j=i;j<=20000;j+=i){
                int cost = std::abs(i - a) + std::abs(j - b) + std::min(c%j, std::abs(j - c%j));
                if(min_cost > cost){
                    min_cost = cost;
                    min_a = i;
                    min_b = j;
                    // std::cout<<c%j<<" "<<std::abs(j-c%j)<<"\n";
                    min_c = c%j < std::abs(j-c%j) ? c-c%j : c+std::abs(j-c%j);
                }
            }
        std::cout<<min_cost<<"\n";
        std::cout<<min_a<<" "<<min_b<<" "<<min_c<<"\n";
    }
}

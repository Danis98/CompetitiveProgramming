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
        int a, b;
        std::cin>>a>>b;
        if(a == b) std::cout<<"0\n";
        else{
            if(a > b){
                if(a%2 == b%2) std::cout<<"1\n";
                else std::cout<<"2\n";
            }
            else{
                if(a%2 == b%2) std::cout<<"2\n";
                else std::cout<<"1\n";
            }
        }
    }
}

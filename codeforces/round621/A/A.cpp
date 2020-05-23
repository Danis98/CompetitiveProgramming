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
        int N, D;
        std::cin>>N>>D;
        std::vector<int> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        for(int i=1;i<N;i++){
            // std::cout<<(D/i)<<" "<<a[i]<<"\n";
            int amt = std::min(D/i, a[i]);
            a[0] += amt;
            D -= amt*i;
        }
        std::cout<<a[0]<<"\n";
    }
}

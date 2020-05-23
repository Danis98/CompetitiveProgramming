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
        int N;
        std::cin>>N;
        std::vector<int> a(N), b(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        for(int i=0;i<N;i++) std::cin>>b[i];
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        for(int i=0;i<N;i++) std::cout<<a[i]<<" ";
        std::cout<<"\n";
        for(int i=0;i<N;i++) std::cout<<b[i]<<" ";
        std::cout<<"\n";
    }
}

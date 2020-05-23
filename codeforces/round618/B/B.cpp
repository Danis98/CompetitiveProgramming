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

    int T, N;
    std::vector<int> A;
    std::cin>>T;
    for(int t=0;t<T;t++){
        std::cin>>N;
        A.resize(2*N);
        for(int i=0;i<2*N;i++) std::cin>>A[i];
        std::sort(A.begin(), A.end());
        std::cout<<(A[N]-A[N-1])<<"\n";
    }
}

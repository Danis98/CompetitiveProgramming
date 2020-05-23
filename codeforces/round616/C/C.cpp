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
        int N, M, K;
        std::cin>>N>>M>>K;
        std::vector<int> A(N);
        for(int i=0;i<N;i++) std::cin>>A[i];
        int X = std::max(0, M - K - 1);
        K = std::min(K, M-1);
        int res = 0;
        for(int i=0;i<=K;i++){
            int res_temp = 1000000000;
            for(int j=0;j<=X;j++){
                // std::cout<<i<<" "<<j<<" "<<(i+j)<<" "<<(N-K-X+i+j-1)<<" "<<A[i+j]<<" "<<A[N-K-X+i+j-1]<<"\n";
                res_temp = std::min(res_temp, std::max(A[i+j], A[N-1-X+j-K+i]));
            }
            res = std::max(res, res_temp);
        }
        std::cout<<res<<"\n";
    }
}

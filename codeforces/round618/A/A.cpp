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
        A.resize(N);
        for(int i=0;i<N;i++) std::cin>>A[i];
        int zeros = 0, sum = 0;
        for(int i=0;i<N;i++){
            if(A[i] == 0) zeros++;
            sum += A[i];
        }
        int moves = zeros;
        sum += moves;
        if(sum == 0) moves++;
        std::cout<<moves<<"\n";
    }
}

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
        int a=0, b=N-1;
        for(int i=0;i<N;i++){
            int ra, rb;
            if(A[i] < i) rb = i-1;
            else rb = N-1;
            if(A[i] < N-i-1) ra = i+1;
            else ra = 0;
            a=std::max(a, ra);
            b=std::min(b, rb);
        }
        if(a<=b) std::cout<<"Yes\n";
        else std::cout<<"No\n";
    }
}

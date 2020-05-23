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

    ll N, M;
    std::cin>>N>>M;
    if(N < 3){
        if(M > 0) std::cout<<"-1\n";
        else for(int i=1;i<=N;i++) std::cout<<i<<" ";
        std::cout<<"\n";
        return 0;
    }
    std::vector<ll> a(N);
    a[0] = 1;
    a[1] = 2;
    ll ctr = 0;
    int inc = 0;
    for(int i=2;i<N;i++){
        ctr += inc;
        inc ^= 1;
        if(ctr <= M){
            a[i]
        }
        else{

        }
    }
}

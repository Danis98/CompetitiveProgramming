#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define MAXN 1000

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll N, D, K;
    std::cin>>N>>K>>D;

    std::vector<int> bus(N);
    for(int i=0;i<N;i++) bus[i] = i % K;
    if(K >= N){
        for(int i=0;i<D;i++){
            for(int j=0;j<N;j++)
                std::cout<<(bus[j]+1)<<" ";
            std::cout<<"\n";
        }
    }
    int div = N / K;
    div += (N % K) == 0 ? 0 : 1;
    if(div > D || K == 1 && N != 1){
        std::cout<<"-1\n";
        return 0;
    }
    for(int i=0;i<N;i++) std::cout<<(bus[i]+1)<<" ";
    std::cout<<"\n";
    for(ll i=1;i<D;i++){
        if(K * i >= N)
            for(int j=0;j<N;j++) std::cout<<(bus[j]+1)<<" ";
        for(int j=0;j<K*i;j++)
            std::cout<<(bus[j]+1)<<" ";
        for(int j=K*i;j<std::min(N, K*(i+1));j++)
            std::cout<<(((bus[j]+1)%K)+1)<<" ";
        for(int j=std::min(N, K*(i+1));j<N;j++)
            std::cout<<(bus[j]+1)<<" ";
        std::cout<<"\n";
    }
}

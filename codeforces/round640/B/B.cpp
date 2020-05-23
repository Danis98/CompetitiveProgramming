#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        ll N, K;
        std::cin>>N>>K;
        //even
        if(N%2 == 0 && N - 2*(K-1) > 0){
            std::cout<<"YES\n";
            for(int i=0;i<K-1;i++) std::cout<<2<<" ";
            std::cout<<(N-2*(K-1))<<"\n";
            continue;
        }
        //odd
        if(K%2 == N%2 && N - K + 1 > 0){
            std::cout<<"YES\n";
            for(int i=0;i<K-1;i++) std::cout<<1<<" ";
            std::cout<<(N-K+1)<<"\n";
            continue;
        }

        std::cout<<"NO\n";
    }
}

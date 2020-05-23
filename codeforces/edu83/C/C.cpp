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

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        ll N, K;
        std::cin>>N>>K;
        std::vector<ll> a(N);
        ll max_a = 0;
        for(int i=0;i<N;i++){
            std::cin>>a[i];
            max_a = std::max(max_a, a[i]);
        }

        ll f = 1;
        while(f < max_a) f *= K;
        while(f){
            for(int i=0;i<N;i++){
                if(a[i] >= f){
                    a[i] -= f;
                    break;
                }
            }
            f /= K;
        }

        bool good = true;
        for(int i=0;i<N;i++)
            if(a[i] != 0) good = false;
        std::cout<<(good ? "YES\n" : "NO\n");
    }
}

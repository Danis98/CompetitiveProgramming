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
    std::vector<std::vector<ll>> m;
    while(T--){
        ll N, M, A, B;
        std::cin>>N>>M>>A>>B;
        if(M*B != N*A){
            std::cout<<"NO\n";
            continue;
        }
        m.assign(N, std::vector<ll>(M, 0));

        for(int i=0;i<N;i++){
            for(int j=0;j<A;j++)
                m[i][(j+i*A)%M] = 1;
        }
        std::cout<<"YES\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                std::cout<<m[i][j];
            std::cout<<"\n";
        }
    }
}

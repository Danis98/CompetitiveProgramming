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

    ll T;
    std::cin>>T;
    while(T--){
        ll N, K;
        std::cin>>N>>K;
        std::vector<std::vector<ll>> grid(N, std::vector<ll>(N, 0));
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++){
                grid[j][(i+j)%N] = K > 0 ? 1 : 0;
                K -= grid[j][(i+j)%N];
            }
        ll minr = N, maxr = 0, minc = N, maxc = 0;
        for(int i=0;i<N;i++){
            ll r = 0, c = 0;
            for(int j=0;j<N;j++){
                r += grid[i][j];
                c += grid[j][i];
            }
            minr = std::min(r, minr);
            maxr = std::max(r, maxr);
            minc = std::min(c, minc);
            maxc = std::max(c, maxc);
        }
        ll f = (maxr-minr)*(maxr-minr)+(maxc-minc)*(maxc-minc);
        std::cout<<f<<"\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                std::cout<<grid[i][j];
            std::cout<<"\n";
        }
    }
}

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
        ll N, M;
        std::cin>>N>>M;
        std::vector<std::vector<ll>> grid(N, std::vector<ll>(M));
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                std::cin>>grid[i][j];
        ll path_len = N + M - 1;
        std::vector<ll> d_ones(path_len+1, 0), d_tot(path_len+1, 0);
        for(ll i=0;i<N;i++)
            for(ll j=0;j<M;j++){
                ll d = std::min(i+j, path_len-i-j-1);
                d_ones[d] += grid[i][j];
                d_tot[d]++;
            }
        ll res = 0;
        for(int i=0;i<path_len/2;i++)
            res += std::min(d_ones[i], d_tot[i]-d_ones[i]);
        std::cout<<res<<"\n";
    }
}

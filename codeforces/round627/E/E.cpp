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

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll N, H, L, R;
    std::cin>>N>>H>>L>>R;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    std::vector<std::vector<ll>> dp(N+2, std::vector<ll>(H, -1));
    dp[0][0] = 0;

    for(int i=0;i<N;i++){
        for(int j=0;j<H;j++){
            // std::cout<<dp[i][j]<<" ";
            if(dp[i][j] == -1) continue;
            dp[i+1][(j+a[i])%H] = std::max(dp[i+1][(j+a[i])%H], dp[i][j] + ((j+a[i])%H>=L && (j+a[i])%H<=R));
            dp[i+1][(j+a[i]-1)%H] = std::max(dp[i+1][(j+a[i]-1)%H], dp[i][j] + ((j+a[i]-1)%H>=L && (j+a[i]-1)%H<=R));
        }
        // std::cout<<"\n";
    }
    ll res = 0;
    for(int i=0;i<H;i++) res = std::max(res, dp[N][i]);
    std::cout<<res<<"\n";
}

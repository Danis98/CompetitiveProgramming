#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int N;
std::vector<ll> a, dp2;
std::vector<std::vector<ll>> dp;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N;
    a.resize(N);
    dp.resize(N, std::vector<ll>(N, -1));
    dp2.resize(N, N);
    for(int i=0;i<N;i++) std::cin>>a[i];

    for(int i=0;i<N;i++) dp[i][i] = a[i];
    for(int d=1;d<N;d++)
        for(int i=0;i<=N-d-1;i++)
            for(int j=i;j<i+d;j++)
                if(dp[i][j] == dp[j+1][i+d] && dp[i][j] != -1){
                    dp[i][i+d] = dp[i][j] + 1;
                    break;
                }

    for(int i=0;i<N;i++) if(dp[0][i] != -1) dp2[i] = 1;
    for(int i=1;i<N;i++)
        for(int j=0;j<i;j++)
            if(dp[j+1][i] != -1)
                dp2[i] = std::min(dp2[j] + 1, dp2[i]);

    std::cout<<dp2[N-1]<<"\n";
}

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

int N, M, K;

std::vector<ll> get_modsums(std::vector<ll>& row){
    std::vector<std::vector<std::vector<ll>>> dp(M, std::vector<std::vector<ll>>(M/2+1, std::vector<ll>(K, 0)));
    std::vector<ll> res(K, 0);
    for(int i=0;i<M;i++){
        for(int j=1;j<=M/2&&j<=i+1;j++){
                // dp[i][j] = max(dp[i-1][j], dp[i][j-1]+row[i])
                for(int k=0;k<K;k++){
                    dp[i][j][k] = i==0?0:dp[i-1][j][k];
                    if(dp[i][j][k] != 0)
                        dp[i][j][(k+row[i])%K] = std::max(dp[i][j][(k+row[i])%K], dp[i][j-1][k] + row[i]);
                    std::cout<<dp[i][j][k]<<" \n"[k==K-1];
                    res[k] = std::max(res[k], dp[i][j][k]);
                }
        }
        std::cout<<"\n";
    }
    return res;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N>>M>>K;
    std::vector<std::vector<ll>> a(N, std::vector<ll>(M));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            std::cin>>a[i][j];
    std::vector<ll> prev(K, 0);
    for(int i=0;i<N;i++){
        std::vector<ll> modsum = get_modsums(a[i]);
        for(int j=0;j<K;j++)
            std::cout<<modsum[j]<<" \n"[j==K-1];

        std::cout<<"----\n";
    }
}

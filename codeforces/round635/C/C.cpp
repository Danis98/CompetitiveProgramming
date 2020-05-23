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

#define MOD 998244353LL

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string S, T;
    std::cin>>S>>T;
    int N = S.length(), M = T.length();

    ll dp[N+1][M][M];
    for(int i=0;i<=N;i++)
        for(int j=0;j<M;j++)
            for(int k=0;k<M;k++)
                dp[i][j][k] = 0;
    ll empty[N+1];
    empty[0] = 1;
    for(int i=1;i<=N;i++)
        empty[i] = (empty[i-1] * 2) % MOD;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            for(int k=j;k<M;k++){
                ll pre_len = k - j + 1;
                dp[i][j][k] = dp[i-1][j][k];
                if(S[i-1] == T[j]){
                    // std::cout<<"["<<i<<" "<<j<<" "<<k<<"]\n";
                    if(pre_len == 1) dp[i][j][k] += empty[i-1];
                    else dp[i][j][k] += dp[i-1][j+1][k];
                }
                if(S[i-1] == T[k] && pre_len == i){
                    // std::cout<<"{"<<i<<" "<<j<<" "<<k<<"}\n";
                    if(pre_len == 1) dp[i][j][k] += empty[i-1];
                    else dp[i][j][k] += dp[i-1][j][k-1];
                }
                dp[i][j][k] %= MOD;
            }
        }
    }

    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<M;j++){
    //         for(int k=0;k<M;k++){
    //             std::cout<<dp[i][j][k]<<" ";
    //         }
    //         std::cout<<"\n";
    //     }
    //     std::cout<<"\n";
    // }

    ll tot = 0;
    for(int i=1;i<=N;i++) tot += dp[i][0][M-1];
    std::cout<<tot%MOD<<"\n";
}

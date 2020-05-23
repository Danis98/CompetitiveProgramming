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
        std::vector<std::vector<ll>> a(N, std::vector<ll>(M));
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                std::cin>>a[i][j];
        std::unordered_set<ll> start;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(a[i][j]-i-j <= a[0][0])
                    start.insert(a[i][j]-i-j);
        ll res = (ll)1e15;
        for(ll s : start){
            std::vector<std::vector<ll>> dp(N, std::vector<ll>(M, -1));
            dp[0][0] = a[0][0] - s;
            a[0][0] = s;
            for(int i=1;i<N;i++)
                if(a[i][0]-i>=a[0][0])
                    dp[i][0] = dp[i-1][0] + a[i][0] - a[0][0] - i;
                else break;
            for(int i=1;i<M;i++)
                if(a[0][i]-i>=a[0][0])
                    dp[0][i] = dp[0][i-1] + a[0][i] - a[0][0] - i;
                else break;
            for(int i=1;i<N;i++){
                for(int j=1;j<M;j++){
                    if(a[i][j] < a[0][0]+i+j) continue;
                    if(dp[i][j-1] == -1 && dp[i-1][j] == -1) continue;
                    dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] += a[i][j] - (a[0][0]+i+j);
                }
            }
            if(dp[N-1][M-1] != -1)
                res = std::min(res, dp[N-1][M-1]);
        }
        std::cout<<res<<"\n";
    }
}

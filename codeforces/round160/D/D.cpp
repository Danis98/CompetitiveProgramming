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

    ll N, P;
    std::cin>>N;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    std::cin>>P;

    std::sort(a.begin(), a.end());
    // std::reverse(a.begin(), a.end());
    // std::vector<std::vector<ll>> dp(P+1, std::vector<ll>(N, 0));
    // for(int i=1;i<=P;i++){
    //     for(int j=0;j<N;j++){
    //         if(a[j] > i) continue;
    //         dp[i][j] = 1;
    //         for(int k=i-a[j];k>=0 && i-a[j]-k<(j==0?0:a[j-1]);k--){
    //             for(int w=j+1;w<N;w++)
    //                 dp[i][j] += dp[k][w];
    //         }
    //     }
    // }

    std::vector<ll> dp(N+1);
    std::vector<ll> pre(N);
    pre[0] = a[0];
    for(int i=1;i<N;i++) pre[i] = pre[i-1] + a[i];
    ll tot = 0;
    for(int i=0;i<N;i++){
        if(a[i] > P) dp[0] += ;
    }
}

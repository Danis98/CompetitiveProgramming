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

    int K;
    std::cin>>K;
    int a[3][4] = {
        {(1<<18)-1, K, K, 0},
        {1<<17, 0, K, 0},
        {1<<17, 1<<17, (1<<18)-1, K}
    };

    std::cout<<"3 4\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++) std::cout<<a[i][j]<<" ";
        std::cout<<"\n";
    }

    // int N, M;
    // std::cin>>N>>M;
    // std::vector<std::vector<int>> a(N+1, std::vector<int>(M+1));
    // for(int i=1;i<=N;i++)
    //     for(int j=1;j<=M;j++)
    //         std::cin>>a[i][j];
    // std::vector<std::vector<int>> dp(N+1, std::vector<int>(M+1, 0));
    // dp[0][1] = a[1][1];
    // for(int i=1;i<=N;i++)
    //     for(int j=1;j<=M;j++)
    //         dp[i][j] = std::max(dp[i-1][j]&a[i][j], dp[i][j-1]&a[i][j]);
    // for(int i=0;i<=N;i++){
    //     for(int j=0;j<=M;j++)
    //         std::cout<<dp[i][j]<<" ";
    //     std::cout<<"\n";
    // }
    // std::cout<<dp[N][M]<<"\n";
}

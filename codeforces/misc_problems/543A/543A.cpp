#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

ll N, M, B, MOD;
std::vector<ll> a;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N>>M>>B>>MOD;
    a.resize(N);
    for(int i=0;i<N;i++) std::cin>>a[i];

    std::vector<std::vector<ll>> dp1(M+1, std::vector<ll>(B+1, 0)), dp2(M+1, std::vector<ll>(B+1, 0));
    for(int i=0;i<=M;i++)
        for(int j=0;j<=B;j++)
            dp1[i][j] = (i*a[0] == j) ? 1%MOD : 0;

    for(int i=1;i<N;i++){
        for(int j=0;j<=M;j++)
            for(int k=0;k<=B;k++){
                dp2[j][k] = (dp1[j][k] + (k>=a[i]&&j>0?dp2[j-1][k-a[i]]:0)) % MOD;
            }
        // for(int j=0;j<=M;j++)
        //     for(int k=0;k<=B;k++)
        //         std::cout<<dp1[j][k]<<" \n"[k==B];
        // std::cout<<"\n";
        dp1 = dp2;
        dp2 = std::vector<std::vector<ll>>(M+1, std::vector<ll>(B+1, 0));
    }

    // for(int j=0;j<=M;j++)
    //     for(int k=0;k<=B;k++)
    //         std::cout<<dp1[j][k]<<" \n"[k==B];

    ll res = 0;
    for(int i=0;i<=B;i++)
        res = (res + dp1[M][i]) % MOD;

    std::cout<<res<<"\n";
}

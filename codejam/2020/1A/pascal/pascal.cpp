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

#define MAXR 500

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<std::vector<ll>> pascal(MAXR+1);
    for(int i=1;i<=MAXR;i++){
        pascal[i] = std::vector<ll>(i+1);
        for(int j=1;j<=i;j++)
            if(j == 1 || j == i) pascal[i][j] = 1;
            else pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
    }

    // std::vector<ll> max(MAXR+1, 0);
    // for(int i=1;i<=MAXR;i++){
    //     for(int j=1;j<=i;j++)
    //         max[j] += pascal[i][j];
    // }
    // for(int i=1;i<=MAXR;i++)
    //     std::cout<<max[i]<<"\n";

    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++){
        std::cout<<"Case #"<<t<<": ";
    }
}

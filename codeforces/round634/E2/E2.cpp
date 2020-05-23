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

#define MAXA 200

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        int N;
        std::cin>>N;
        std::vector<int> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        std::vector<std::vector<int>> pre(MAXA+1, std::vector<int>(N, 0)), pre_inv(MAXA+1, std::vector<int>(1, 0));
        pre[a[0]][0] = 1;
        for(int i=1;i<N;i++){
            for(int j=1;j<=MAXA;j++)
                pre[j][i] = pre[j][i-1];
            pre[a[i]][i]++;
        }
        for(int i=0;i<N;i++)
            pre_inv[a[i]].pb(i);

        int best = 0;
        for(int i=1;i<=MAXA;i++) best = std::max(best, pre[i][N-1]);

        for(int i=0;i<N;i++){
            int opp = pre_inv[a[i]][pre[a[i]][N-1]-pre[a[i]][i]+1];
            if(opp <= i) continue;
            int outer = 2 * pre[a[i]][i];
            int inner = 0;
            for(int j=1;j<=MAXA;j++)
                inner = std::max(inner, pre[j][opp-1]-pre[j][i]);
            best = std::max(best, outer + inner);
        }
        std::cout<<best<<"\n";
    }
}

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
        std::vector<ll> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        std::vector<std::vector<ll>> pre(MAXA+1, std::vector<ll>(N, 0)), post(MAXA+1, std::vector<ll>(N, 0));
        pre[a[0]][0] = 1;
        for(int i=1;i<N;i++){
            for(int j=1;j<=MAXA;j++)
                pre[j][i] = pre[j][i-1];
            pre[a[i]][i]++;
        }

        ll best = 0;
        for(int i=1;i<=MAXA;i++) best = std::max(best, pre[i][N-1]);
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(a[i] != a[j]) continue;
                ll outer = 2 * std::min(pre[a[i]][i], pre[a[j]][N-1]-pre[a[j]][j-1]);
                ll inner = 0;
                for(int k=1;k<=MAXA;k++)
                    inner = std::max(inner, pre[k][j-1]-pre[k][i]);
                best = std::max(best, outer+inner);
            }
        }
        std::cout<<best<<"\n";
    }
}

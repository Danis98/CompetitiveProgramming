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
        int N, M;
        std::cin>>N>>M;
        std::vector<std::vector<int>> a(N, std::vector<int>(M, 0));
        a[0][0] = 1;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                std::cout<<("BW"[a[i][j]]);
            std::cout<<"\n";
        }
    }
}

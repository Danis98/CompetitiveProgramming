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
        ll rows = 0, cols = 0;
        for(int i=0;i<N;i++){
            bool good = true;
            for(int j=0;j<M;j++)
                good &= a[i][j] == 0;
            if(good) rows++;
        }
        for(int i=0;i<M;i++){
            bool good = true;
            for(int j=0;j<N;j++)
                good &= a[j][i] == 0;
            if(good) cols++;
        }
        ll num = std::min(rows, cols);
        if(num%2) std::cout<<"Ashish\n";
        else std::cout<<"Vivek\n";
    }
}

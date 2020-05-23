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

#define MAXN 1000
#define MAXA 1000

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    int T;
    std::cin>>T;
    while(T--){
        int N;
        std::cin>>N;
        std::vector<int> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        std::map<int, int> col_map;
        std::vector<int> col(N);
        int col_ctr = 1;
        for(int i=0;i<N;i++){
            for(int j=0;j<primes.size();j++){
                if(a[i]%primes[j] == 0){
                    if(col_map[j] == 0) col_map[j] = col_ctr++;
                    col[i] = col_map[j];
                    break;
                }
            }
        }
        std::cout<<col_ctr-1<<"\n";
        for(int i=0;i<N;i++) std::cout<<col[i]<<" ";
        std::cout<<"\n";
    }
}

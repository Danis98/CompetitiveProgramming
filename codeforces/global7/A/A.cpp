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

    int T;
    std::cin>>T;
    while(T--){
        int N;
        std::cin>>N;
        if(N == 1) std::cout<<"-1\n";
        else{
            std::vector<int> d(N);
            d[N-1] = 9;
            d[N-2] = 4;
            int ctr = 0;
            int dig[4] = {9, 4, 9, 5};
            for(int i=N-3;i>=0;i--)
                d[i] = dig[(ctr++)%4];
            for(int i=0;i<N;i++) std::cout<<d[i];
            std::cout<<"\n";
        }
    }
}

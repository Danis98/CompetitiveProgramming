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
        int N;
        std::cin>>N;
        std::vector<ll> a(N), b(N);
        for(int i=0;i<N;i++) std::cin>>a[i]>>b[i];
        ll res = 0;
        for(int i=0;i<N;i++) res += std::max(0LL, a[(i+1)%N] - b[i]);
        ll m = 1000000000001;
        for(int i=0;i<N;i++)
            m = std::min(m, std::min(a[(i+1)%N], b[i]));
        res += m;
        std::cout<<res<<"\n";
    }
}

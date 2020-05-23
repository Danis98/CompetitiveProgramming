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

ll D, M;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        std::cin>>D>>M;
        std::vector<ll> p2(32), pre(32);
        p2[0] = 1;
        pre[0] = 0;
        for(int i=1;i<32;i++){
            ll p = 1LL << i;
            ll p1 = 1LL << (i-1);
            pre[i] = p2[i-1] + (p - p1 - 1) * (pre[i-1]+1LL);
            ll inc1 = pre[i];
            p2[i] = pre[i] + pre[i] + 1;
            pre[i] %= M;
            p2[i] %= M;
        }
        int logD = 0;
        while((1LL << logD) <= D) logD++;
        logD--;
        ll res = p2[logD] + (pre[logD]+1) * (D - (1LL << logD));
        res %= M;
        std::cout<<res<<"\n";
    }
}

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
        ll N, K;
        std::cin>>N>>K;
        std::string S;
        std::cin>>S;
        ll s = 0;
        while(s<N && S[s]=='0') s++;
        if(s==N){
            ll r = (N+K)/(K+1);
            std::cout<<r<<"\n";
            continue;
        }
        ll res = s / (K+1);
        ll e = N-1;
        while(e >= 0 && S[e]=='0') e--;
        res += (N-1-e) / (K+1);
        for(int i=s+1;i<=e;i++){
            if(S[i]=='0') continue;
            res += std::max(0LL, (i-s-K-1))/(K+1);
            s = i;
        }
        std::cout<<res<<"\n";
    }
}

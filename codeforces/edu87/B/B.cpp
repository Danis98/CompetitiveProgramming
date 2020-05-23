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
        ll N;
        std::string S;
        std::cin>>S;
        N = S.length();
        std::vector<std::vector<ll>> prev(4, std::vector<ll>(N, -1));
        for(int i=0;i<N;i++){
            if(i > 0)
                for(int j=1;j<=3;j++)
                    prev[j][i] = prev[j][i-1];
            prev[S[i]-'0'][i] = i;
        }

        ll res = 0;
        for(int i=0;i<N;i++){
            ll s = i;
            for(int j=1;j<=3;j++)
                s = std::min(s, prev[j][i]);
            if(s == -1) continue;
            ll len = i - s + 1;
            if(res == 0 || res > len) res = len;
        }
        std::cout<<res<<"\n";
    }
}

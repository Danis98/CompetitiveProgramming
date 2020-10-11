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
        std::string S;
        std::cin>>S;
        ll N = S.length();
        std::vector<ll> req(N+1, 0);
        ll ctr = 0;
        for(int i=0;i<=N;i++){
            if(i>0) req[i] = std::max(req[i-1], -ctr);
            if(i<N){
                if(S[i]=='-') ctr--;
                else ctr++;
            }
        }
        ll m = req[N];
        ll res = 0;
        // for(int i=0;i<=N;i++)
        //     std::cout<<req[i]<<" \n"[i==N];
        for(int i=0;i<N;i++)
            res += m - req[i] + 1;
        std::cout<<res<<"\n";
    }
}

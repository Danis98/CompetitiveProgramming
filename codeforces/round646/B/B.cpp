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
        std::vector<ll> pre0(N, 0), pre1(N, 0);
        for(int i=0;i<N;i++){
            if(i>0){
                pre0[i] = pre0[i-1];
                pre1[i] = pre1[i-1];
            }
            if(S[i]=='0') pre0[i]++;
            else pre1[i]++;
        }
        ll res = std::min(pre0[N-1], pre1[N-1]);
        for(int i=0;i<N;i++){
            res = std::min(res, pre0[i]+pre1[N-1]-pre1[i]);
            res = std::min(res, pre1[i]+pre0[N-1]-pre0[i]);
        }
        std::cout<<res<<"\n";
    }
}

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
        std::cin>>N;
        std::vector<ll> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        std::vector<ll> O(N, 0), E(N, 0);
        for(int i=0;i<N;i++){
            if(i>0){
                O[i] = O[i-1];
                E[i] = E[i-1];
            }
            if(i%2==0) E[i] += a[i];
            else O[i] += a[i];
        }
        ll res = E[N-1];
        ll bestO = 0, bestE = 0;
        // for(int i=0;i<N;i++)
        //     std::cout<<O[i]<<" \n"[i==N-1];
        // for(int i=0;i<N;i++)
        //     std::cout<<E[i]<<" \n"[i==N-1];
        for(int i=0;i<N;i++){
            ll d = O[i] - E[i];
            if(i%2==0){
                res = std::max(E[N-1]+d-bestE, res);
                bestE = std::min(bestE, d);
            }
            else{
                res = std::max(E[N-1]+d-bestO, res);
                bestO = std::min(bestO, d);
            }
        }
        std::cout<<res<<"\n";
    }
}

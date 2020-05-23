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

    ll N, M, K;
    std::cin>>N>>M>>K;
    if(4*N*M-2*N-2*M < K){
        std::cout<<"NO\n";
        return 0;
    }
    ll ctr = 0;
    std::vector<std::pair<ll, std::string>> moves;
    if(K <= M-1) moves.pb({K, "R"});
    else{
        if(M-1 > 0) moves.pb({M-1, "R"});
        if(K <= 2*(M-1)) moves.pb({K-M+1, "L"});
        else{
            if(M-1 > 0) moves.pb({M-1, "L"});
            ctr = 2*(M-1);
            for(int i=1;i<N && ctr<K;i++){
                ctr++;
                moves.pb({1, "D"});
                ll r = std::min((K - ctr) / 3, M-1);
                ctr += 3*r;
                if(r > 0) moves.pb({r, "RUD"});
                if(r < M-1){
                    if(K - ctr == 0){}
                    else if(K - ctr == 1) moves.pb({1, "R"});
                    else if(K-ctr == 2) moves.pb({1, "RU"});
                    ctr += K-ctr;
                }
                else{
                    ll l = std::min(std::max(0LL, K-ctr), r);
                    ctr += l;
                    if(l > 0) moves.pb({l, "L"});
                }
            }
            if(ctr < K){
                moves.pb({K-ctr, "U"});
            }
        }
    }

    std::cout<<"YES\n";
    std::cout<<moves.size()<<"\n";
    for(auto move : moves)
        std::cout<<move.fi<<" "<<move.se<<"\n";
}

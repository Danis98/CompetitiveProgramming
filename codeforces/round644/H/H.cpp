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
        ll N, M;
        std::cin>>N>>M;
        std::set<ll> a;
        for(int i=0;i<N;i++){
            std::string s;
            std::cin>>s;
            ll v = 0;
            for(int j=0;j<M;j++)
                v = 2*v + s[j] - '0';
            a.insert(v);
        }
        ll med = (1LL << (M-1))-1;
        ll res = -1;
        for(ll cand=std::max(0LL, med-100);cand<=std::min((1LL<<M)-1, cand+100);cand++){
            if(a.find(cand) != a.end()) continue;
            ll k = (1LL << M)-N-1;
            ll p = cand;
            for(ll v : a)
                if(v < cand) p--;
            // std::cout<<"["<<cand<<" ";
            // for(int i=M-1;i>=0;i--)
            //     std::cout<<((cand>>i)&1);
            // std::cout<<" "<<p<<" "<<k<<"]\n";
            if(p == k/2){
                res = cand;
                break;
            }
        }
        for(int i=M-1;i>=0;i--)
            std::cout<<((res>>i)&1);
        std::cout<<"\n";
    }
}

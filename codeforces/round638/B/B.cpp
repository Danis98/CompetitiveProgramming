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
        std::vector<ll> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        ll sup = a[0];
        std::set<ll> S;
        for(int i=0;i<N;i++){
            sup = std::max(sup, a[i]);
            S.insert(a[i]);
        }

        if(S.size() > K){
            std::cout<<"-1\n";
            continue;
        }

        std::cout<<N*K<<"\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<K-S.size();j++) std::cout<<sup<<" ";
            for(ll e : S)
                std::cout<<e<<" ";
        }
        std::cout<<"\n";
    }
}

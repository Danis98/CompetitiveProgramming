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

    ll N, M;
    std::cin>>N>>M;
    std::vector<std::vector<ll>> G(N);
    for(int i=0;i<M;i++){
        ll a, b;
        std::cin>>a>>b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    std::vector<ll> t(N), e(N, 1);
    std::vector<std::vector<ll>> classes(N+1);
    for(int i=0;i<N;i++) std::cin>>t[i];
    for(int i=0;i<N;i++) classes[t[i]].pb(i);
    bool poss = true;
    for(ll c=1;c<=N;c++){
        for(ll n : classes[c]){
            if(e[n] != c){
                poss = false;
                break;
            }
            for(ll neigh : G[n])
                if(e[neigh] == c) e[neigh] = c+1;
        }
        if(!poss) break;
    }
    if(!poss) std::cout<<"-1\n";
    else{
        for(int c=1;c<=N;c++)
            for(ll n : classes[c]) std::cout<<(n+1)<<" ";
        std::cout<<"\n";
    }
}

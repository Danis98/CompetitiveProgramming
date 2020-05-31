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

ll N, X;
std::vector<std::vector<ll>> tree;

ll get_sub(int n, int p){
    ll s = 1;
    for(ll neigh : tree[n])
        if(neigh != p) s += get_sub(neigh, n);
    return s;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        std::cin>>N>>X;
        tree.assign(N, std::vector<ll>());
        for(int i=0;i<N-1;i++){
            ll a, b;
            std::cin>>a>>b;
            a--;
            b--;
            tree[a].pb(b);
            tree[b].pb(a);
        }

        if(tree[X-1].size() <= 1 || (N%2) == 0) std::cout<<"Ayush\n";
        else std::cout<<"Ashish\n";
    }
}

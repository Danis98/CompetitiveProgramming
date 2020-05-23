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

    int N, M;
    std::cin>>N>>M;
    std::vector<ll> longest_so_far(N, 0);
    std::vector<ll3> edges;
    std::unordered_map<ll, ll> to_upd;
    for(int i=0;i<M;i++){
        int a, b, w;
        std::cin>>a>>b>>w;
        a--;
        b--;
        edges.pb({w, {a, b}});
    }
    std::sort(edges.begin(), edges.end());
    for(int i=0;i<M;i++){
        if(i > 0 && edges[i].fi != edges[i-1].fi){
            for(auto n : to_upd)
                longest_so_far[n.fi] = std::max(longest_so_far[n.fi], n.se);
            to_upd.clear();
        }
        to_upd[edges[i].se.se] = std::max(to_upd[edges[i].se.se], longest_so_far[edges[i].se.fi] + 1);
        // for(int j=0;j<N;j++) std::cout<<longest_so_far[j]<<" ";
        // std::cout<<"\n";
    }
    for(auto n : to_upd)
        longest_so_far[n.fi] = std::max(longest_so_far[n.fi], n.se);
    // for(int j=0;j<N;j++) std::cout<<longest_so_far[j]<<" ";
    // std::cout<<"\n";
    ll res = 0;
    for(int i=0;i<N;i++)
        res = std::max(res, longest_so_far[i]);
    std::cout<<res<<"\n";
}

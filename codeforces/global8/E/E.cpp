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

ll N, M;
std::vector<std::vector<ll>> dag;
std::vector<bool> vis;
std::vector<ll> topo_order;

void topo_visit(int n){
    if(vis[n]) return;
    vis[n] = true;
    for(ll neigh : dag[n])
        topo_visit(neigh);
    topo_order.pb(n);
}

void toposort(){
    topo_order.clear();
    vis.assign(N, false);
    for(int i=0;i<N;i++)
        if(!vis[i]) topo_visit(i);
    std::reverse(topo_order.begin(), topo_order.end());
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
        std::cin>>N>>M;
        dag.assign(N, std::vector<ll>());
        for(int i=0;i<M;i++){
            ll a, b;
            std::cin>>a>>b;
            dag[a-1].pb(b-1);
        }
        toposort();
        std::vector<ll> del(N, false), alive_par(N, false);
        for(int i=0;i<N;i++){
            ll idx = topo_order[i];
            if(del[idx]) continue;
            if(dag[idx].size() == 0) continue;
            ll ch1 = dag[idx][0], ch2 = dag[idx][dag[idx].size()-1];
            std::cout<<idx<<" "<<ch1<<" "<<ch2<<"\n";
            if(alive_par[idx] && ch1 != ch2 && !del[ch1] && !del[ch2])
                del[i] = true;
            else if(alive_par[idx]){
                del[ch1] = true;
                del[ch2] = true;
            }
            else{
                alive_par[ch1] = true;
                alive_par[ch2] = true;
            }
        }
        for(int i=0;i<N;i++)
            std::cout<<del[topo_order[i]]<<" \n"[i==N-1];
        for(int i=0;i<N;i++)
            std::cout<<alive_par[topo_order[i]]<<" \n"[i==N-1];
        std::vector<ll> res;
        for(int i=0;i<N;i++)
            if(del[topo_order[i]]) res.pb(topo_order[i]+1);
        std::cout<<res.size()<<"\n";
        for(ll d : res) std::cout<<d<<" ";
        std::cout<<"\n";
    }
}

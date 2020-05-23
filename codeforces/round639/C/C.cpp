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
std::vector<std::vector<ll>> G, G_inv;
std::vector<bool> vis, cur;

bool dfs(int n, int p){
    cur[n] = true;
    vis[n] = true;
    bool ret = false;
    for(ll neigh : G[n]){
        if(neigh == p) continue;
        ret |= (cur[neigh] || !vis[neigh] && dfs(neigh, n));
    }
    cur[n] = false;
    return ret;
}

bool has_cycle(){
    for(int i=0;i<G.size();i++){
        if(vis[i]) continue;
        if(dfs(i, -1))return true;
    }
    return false;
}


int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N>>M;
    G.resize(N);
    G_inv.resize(N);
    vis.assign(N, false);
    cur.assign(N, false);

    for(int i=0;i<M;i++){
        ll a, b;
        std::cin>>a>>b;
        G[a-1].pb(b-1);
        G_inv[b-1].pb(a-1);
    }

    if(has_cycle()){
        std::cout<<"-1\n";
        return 0;
    }

    std::string S = "";
    int ctr = 0;
    for(int i=0;i<N;i++)
        if(G_inv[i].size() == 0){
            S += "A";
            ctr++;
        }
        else S += "E";
    std::cout<<ctr<<"\n"<<S<<"\n";
    for(int i=0;i<N;i++)
        std::cout<<G_inv[i].size()<<" \n"[i==N-1];
}

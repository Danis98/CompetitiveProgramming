std::vector<std::vector<ll>> G;
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

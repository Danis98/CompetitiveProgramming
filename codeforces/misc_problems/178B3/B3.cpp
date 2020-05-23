#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

struct disjoint_set{
    std::vector<int> p, rank;
    disjoint_set(){}
    disjoint_set(int N){
        rank.assign(N, 0);
        p.assign(N, 0); for(int i=0;i<N;i++) p[i] = i;
    }
    int find(int a){return p[a] == a ? a : (p[a] = find(p[a]));}
    bool same_set(int a, int b){return find(a) == find(b);}
    void union_set(int a, int b){
        if(same_set(a, b)) return;
        int ra = find(a), rb = find(b);
        if(rank[ra] > rank[rb]) p[rb] = ra;
        else{
            p[ra] = rb;
            if(rank[ra] == rank[rb]) rank[rb]++;
        }
    }
};

struct tree_lca{
    std::vector<std::vector<int>> _lca;
    std::vector<int> depth;
    int N, logN;
    tree_lca(std::vector<int> par, std::vector<int> d){
        N = par.size();
        int p = 1;
        while(1<<p < N) p++;
        logN = p;
        _lca.resize(p);
        for(int i=0;i<p;i++) _lca[i].assign(N, -1);
        for(int i=0;i<N;i++) _lca[0][i] = par[i];
        for(int i=1;i<p;i++)
            for(int j=0;j<N;j++)
                _lca[i][j] = _lca[i-1][_lca[i-1][j]];
        depth = std::vector<int> (d);
    }
    int lca(int a, int b){
        if(depth[a] > depth[b]) std::swap(a, b);
        b = lift(b, depth[b] - depth[a]);
        if(a == b) return a;
        for(int i=logN-1;i>=0;i--)
            if(_lca[i][a] != _lca[i][b]){
                a = _lca[i][a];
                b = _lca[i][b];
            }
        return _lca[0][a];
    }
    int lift(int a, int steps){
        if(steps <= 0) return a;
        for(int i=logN-1;i>=0;i--)
            if(1<<i <= steps){
                a = _lca[i][a];
                steps -= 1<<i;
            }
        return a;
    }
    int dist(int a, int b){
        int p = lca(a, b);
        return depth[a] + depth[b] - 2*depth[p];
    }
    int walk(int a, int b, int steps){
        int p = lca(a, b);
        int d = dist(a, b);
        if(steps >= d) return b;
        else if(p == a) return lift(b, depth[b] - depth[a] - steps);
        else if(steps <= depth[a] - depth[p])
            return lift(a, steps);
        else return lift(b, depth[b] + depth[a] - steps);
    }
};

int N, M;
int ctr = 0;
std::vector<std::vector<int>> G, tree;
std::vector<int> dfs_num, dfs_low, par, depth;
disjoint_set node_sets;

void get_bridges(int n, int p){
    dfs_num[n] = dfs_low[n] = ctr++;
    for(int neigh : G[n]){
        if(dfs_num[neigh] == -1){
            get_bridges(neigh, n);
            if(dfs_low[neigh] <= dfs_num[n])
                node_sets.union_set(n, neigh);
            dfs_low[n] = std::min(dfs_low[n], dfs_low[neigh]);
        }
        else if(neigh != p)
            dfs_low[n] = std::min(dfs_low[n], dfs_num[neigh]);
    }
}

void dfs(int n, int p){
    par[n] = p;
    if(p == -1) depth[n] = 0;
    else depth[n] = depth[p] + 1;
    for(int ch : tree[n])
        if(ch != p) dfs(ch, n);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M;
    G.resize(N);
    dfs_num.assign(N, -1);
    dfs_low.assign(N, -1);
    node_sets = disjoint_set(N);
    tree.resize(N);
    par.assign(N, -1);
    depth.assign(N, 0);

    for(int i=0;i<M;i++){
        int a, b;
        std::cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    get_bridges(0, -1);

    // for(int i=0;i<N;i++)
    //     std::cout<<i<<": "<<dfs_num[i]<<" "<<dfs_low[i]<<" "<<node_sets.find(i)<<"\n";
    std::set<ii> edges;
    for(int i=0;i<N;i++)
        for(int neigh : G[i]){
            int ra = node_sets.find(i), rb = node_sets.find(neigh);
            if(ra == rb || edges.find({ra, rb}) != edges.end()) continue;
            tree[ra].push_back(rb);
            tree[rb].push_back(ra);
            edges.insert({ra, rb});
            edges.insert({rb, ra});
        }
    int root = node_sets.find(0);
    // for(int u=0;u<N;u++){
    //     std::cout<<u<<": ";
    //     for(int v : tree[u])
    //         std::cout<<v<<" ";
    //     std::cout<<"\n";
    // }

    dfs(root, -1);
    for(int i=0;i<N;i++) if(par[i] == -1) par[i] = i;
    tree_lca lca(par, depth);
    int K;
    std::cin>>K;
    for(int i=0;i<K;i++){
        int a, b;
        std::cin>>a>>b;
        a--;
        b--;
        int ra = node_sets.find(a), rb = node_sets.find(b);
        std::cout<<lca.dist(ra, rb)<<"\n";
    }
}

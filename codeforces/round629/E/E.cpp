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

struct tree_lca{
    std::vector<std::vector<int>> _lca;
    std::vector<int> depth;
    int N, logN;
    tree_lca(){}
    // DO NOT PUT -1 AS ROOT'S PAR, PUT ROOT ITSELF
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
std::vector<std::vector<int>> tree;
std::vector<int> par, depth;

void dfs(int n, int p){
    par[n] = p;
    depth[n] = p == -1 ? 0 : (depth[p]+1);
    for(int ch : tree[n])
        if(ch != p)
            dfs(ch, n);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M;
    std::cin>>N>>M;
    tree.resize(N);
    for(int i=0;i<N-1;i++){
        int a, b;
        std::cin>>a>>b;
        a--;
        b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    par.resize(N);
    depth.resize(N);
    dfs(0, 0);
    tree_lca lca(par, depth);

    for(int i=0;i<M;i++){
        int k;
        std::cin>>k;
        std::vector<int> v(k);
        int deepest = -1;
        for(int j=0;j<k;j++){
            std::cin>>v[j];
            v[j]--;
            if(deepest == -1 || depth[deepest] < depth[v[j]])
                deepest = v[j];
        }
        bool valid = true;
        for(int j=0;j<k && valid;j++){
            int n_lca = lca.lca(deepest, v[j]);
            valid &= lca.dist(deepest, n_lca) <= 1 || lca.dist(v[j], n_lca) <= 1;
        }
        if(valid) std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
}

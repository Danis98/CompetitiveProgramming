#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

struct tree_lca{
    std::vector<std::vector<int>> _lca;
    std::vector<int> depth;
    int N, logN;
    tree_lca(){}
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


int N;
std::vector<std::vector<int>> tree;
std::vector<int> par, depth;
tree_lca lca;

void dfs(int n, int p, int d){
    par[n] = p;
    depth[n] = d;
    for(int ch : tree[n])
        if(ch != p) dfs(ch, n, d+1);
}

bool is_in_cyc(int n, int x, int y){
    bool anc_x = lca.lca(n, x) == n;
    bool anc_y = lca.lca(n, y) == n;
    bool is_cyc_head = lca.lca(x, y) == n;
    return (anc_x ^ anc_y) || is_cyc_head;
}

int find_closest_cyc(int n, int x, int y){
    if(is_in_cyc(n, x, y)) return n;
    int cyc_head = lca.lca(x, y);
    if(lca.lca(n, cyc_head) != cyc_head) return cyc_head;
    int x_lca = lca.lca(n, x);
    int y_lca = lca.lca(n, y);
    if(x_lca != cyc_head) return x_lca;
    if(y_lca != cyc_head) return y_lca;
    return cyc_head;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    tree.resize(N);
    par.resize(N);
    depth.resize(N);
    for(int i=0;i<N-1;i++){
        int a, b;
        std::cin>>a>>b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0, 0, 0);
    lca = tree_lca(par, depth);
    int Q;
    std::cin>>Q;
    for(int q=0;q<Q;q++){
        int x, y, a, b, k;
        std::cin>>x>>y>>a>>b>>k;
        x--;
        y--;
        a--;
        b--;
        int orig_dist = lca.dist(a, b);
        if(orig_dist <= k && orig_dist % 2 == k % 2){
            std::cout<<"YES\n";
            continue;
        }
        int cyc_len = lca.dist(x, y) + 1;
        int d = 0;
        int ra = find_closest_cyc(a, x, y);
        int rb = find_closest_cyc(b, x, y);
        d += lca.dist(a, ra) + lca.dist(b, rb);
        int d1 = d + lca.dist(ra, rb);
        if(d1 <= k && d1 % 2 == k % 2 || d1 + cyc_len <= k && (d1 + cyc_len) % 2 == k % 2){
            std::cout<<"YES\n";
            continue;
        }
        int d2 = d + cyc_len - lca.dist(ra, rb);
        if(d2 <= k && d2 % 2 == k % 2 || d2 + cyc_len <= k && (d2 + cyc_len) % 2 == k % 2){
            std::cout<<"YES\n";
            continue;
        }
        std::cout<<"NO\n";
    }
}

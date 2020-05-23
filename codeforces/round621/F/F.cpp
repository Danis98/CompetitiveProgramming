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
        // std::cout<<"in lca N="<<N<<"\n";
        //_lca.assign(p, std::vector<int> (N, 0));
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

int N, K, R;
std::vector<std::vector<int>> tree;
std::vector<int> par, depth;
std::vector<bool> rest;
disjoint_set *S;

void dfs(int n, int p, int d){
    par[n] = p;
    depth[n] = d;
    for(int ch : tree[n]){
        if(ch == p) continue;
        dfs(ch, n, d+1);
    }
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>K>>R;
    tree.resize(2*N-1);
    rest.resize(2*N-1, false);
    par.resize(2*N-1, -1);
    depth.resize(2*N-1, 0);
    S = new disjoint_set(2*N-1);

    int ctr = N;
    for(int i=0;i<N-1;i++){
        int a, b;
        std::cin>>a>>b;
        a--;
        b--;
        tree[a].push_back(ctr);
        tree[ctr].push_back(a);
        tree[b].push_back(ctr);
        tree[ctr].push_back(b);
        ctr++;
    }
    for(int i=0;i<R;i++){
        int tmp;
        std::cin>>tmp;
        rest[tmp-1] = true;
    }

    std::vector<int> dist(2*N-1, 2*N+1);
    std::queue<int> Q;
    for(int i=0;i<2*N-1;i++){
        if(!rest[i]) continue;
        Q.push(i);
        dist[i] = 0;
    }
    while(!Q.empty()){
        int n = Q.front();
        Q.pop();
        if(dist[n] > K) continue;
        for(auto ch : tree[n]){
            if(dist[n] + 1 <= K)
                S->union_set(n, ch);
            if(dist[ch] > dist[n] + 1){
                dist[ch] = dist[n] + 1;
                Q.push(ch);
            }
        }
    }

    // for(int i=0;i<2*N;i++) std::cout<<i<<": "<<S->find(i)<<","<<dist[i]<<"\n";
    // std::cout<<"\n";
    dfs(0, 0, 0);
    tree_lca lca(par, depth);

    // std::cout<<"in main N="<<N<<"\n";

    int v;
    std::cin>>v;
    for(int i=0;i<v;i++){
        int a, b;
        std::cin>>a>>b;
        // std::cout<<a<<" "<<b<<"\n";
        a--;
        b--;
        // std::cout<<a<<" "<<b<<" -> "<<"("<<lca.lca(a, b)<<")"<<lca.dist(a, b)<<"\n";
        if(S->same_set(a, b) || lca.dist(a, b) <= 2*K)
            std::cout<<"YES\n";
        else{
            // std::cout<<"NOT DIRECT\n";
            int na = lca.walk(a, b, K+1);
            int nb = lca.walk(b, a, K+1);
            // std::cout<<na<<" "<<nb<<"\n";
            if(S->same_set(na, nb))
                std::cout<<"YES\n";
            else std::cout<<"NO\n";
        }
    }
}

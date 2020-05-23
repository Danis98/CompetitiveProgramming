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
        p.assign(N, 0);
        for(int i=0;i<N;i++) p[i] = i;
    }
    int find(int a){
        return p[a] == a ? a : (p[a] = find(p[a]));
    }
    void union_set(int a, int b){
        int ra = find(a), rb = find(b);
        if(ra == rb) return;
        if(rank[ra] > rank[rb]) p[rb] = ra;
        else{
            p[ra] = rb;
            if(rank[ra] == rank[rb]) rank[rb]++;
        }
    }
    bool same_set(int a, int b){ return find(a) == find(b);}
};

int N, M;
std::vector<std::vector<ii>> G;
std::vector<iii> edges;
disjoint_set nodes;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M;
    G.resize(N);
    edges.resize(M);
    nodes = disjoint_set(N);
    for(int i=0;i<M;i++){
        int a, b, r;
        std::cin>>a>>b>>r;
        edges[i] = {r, {a, b}};
        G[a].push_back({b, r});
        G[b].push_back({a, r});
    }
    std::sort(edges.begin(), edges.end());
    int res = -1;
    for(int i=M-1;i>=0;i--){
        iii edge = edges[i];
        int a = edge.second.first, b = edge.second.second, r = edge.first;
        if(nodes.same_set(a, b)) continue;
        res = r;
        nodes.union_set(a, b);
    }
    std::cout<<res<<"\n";
}

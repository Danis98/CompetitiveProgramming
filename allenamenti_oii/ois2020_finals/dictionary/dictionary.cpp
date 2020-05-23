#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int N, D;
std::unordered_map<std::string, std::vector<std::string>> G, G_inv;
std::unordered_map<std::string, bool> vis, mark;
std::deque<std::string> L;
std::unordered_map<std::string, int> comp;
std::unordered_map<int, std::string> comp_str;
int comp_ctr = 0;

void dfs(std::string n){
    if(vis[n]) return;
    vis[n] = true;
    for(std::string neigh : G[n])
        dfs(neigh);
    L.push_front(n);
}

void assign(std::string s, int root){
    if(comp.find(s) == comp.end()){
        comp[s] = root;
        for(std::string n : G_inv[s])
            assign(n, root);
    }
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>D;
    for(int i=0;i<D;i++){
        std::string w;
        std::cin>>w;
        int n;
        std::cin>>n;
        for(int j=0;j<n;j++){
            std::string w2;
            std::cin>>w2;
            G[w].push_back(w2);
            G_inv[w2].push_back(w);
        }
    }

    for(auto entry : G)
        if(!vis[entry.first]) dfs(entry.first);
    for(std::string s : L){
        comp_str[comp_ctr] = s;
        assign(s, comp_ctr++);
    }

    std::vector<std::vector<int>> tree(N);
    std::set<ii> edges;
    for(auto entry : G){
        int c = comp[entry.first];
        for(std::string neigh : entry.second){
            int cc = comp[neigh];
            if(edges.find({c, cc}) != edges.end()) continue;
            edges.insert({c, cc});
            edges.insert({cc, c});
            tree[c].push_back(cc);
        }
    }
    // for(auto entry : comp_str){
    //     std::cout<<entry.second<<": ";
    //     for(int n : tree[entry.first]) std::cout<<comp_str[n]<<" ";
    //     std::cout<<"\n";
    // }

    std::unordered_set<std::string> res;
    for(auto entry : G){
        if(tree[comp[entry.first]].size() == 0) res.insert(comp_str[comp[entry.first]]);
        for(int neigh : tree[comp[entry.first]])
            if(neigh == comp[entry.first]) res.insert(comp_str[neigh]);
    }
    std::cout<<res.size()<<"\n";
    for(std::string s : res)
        std::cout<<s<<"\n";
}

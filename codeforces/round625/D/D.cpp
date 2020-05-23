#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N, M;
    std::cin>>N>>M;
    std::vector<std::vector<int>> G(N);
    for(int i=0;i<M;i++){
        int a, b;
        std::cin>>a>>b;
        a--;
        b--;
        // G[a].push_back(b);
        G[b].push_back(a);
    }
    int K;
    std::cin>>K;
    std::vector<int> path(K);
    for(int i=0;i<K;i++){
        std::cin>>path[i];
        path[i]--;
    }

    std::vector<std::unordered_set<int>> opt(N);
    std::queue<int> Q;
    std::vector<int> dist(N, N+1);
    Q.push(path[K-1]);
    dist[path[K-1]] = 0;
    while(!Q.empty()){
        int n = Q.front();
        Q.pop();
        for(int neigh : G[n]){
            if(dist[neigh] < dist[n] + 1 || opt[neigh].find(n) != opt[neigh].end()) continue;
            dist[neigh] = dist[n] + 1;
            opt[neigh].insert(n);
            Q.push(neigh);
        }
    }
    int min_r = 0, max_r = 0;
    for(int i=0;i<K-1;i++){
        bool is_opt = opt[path[i]].find(path[i+1]) != opt[path[i]].end();
        // std::cout<<"opt["<<path[i]<<"]: ";
        // for(int o : opt[path[i]]) std::cout<<o<<" ";
        // std::cout<<"\n";
        if(!is_opt){
            min_r++;
            max_r++;
        }
        else if(opt[path[i]].size() > 1) max_r++;
    }
    std::cout<<min_r<<" "<<max_r<<"\n";
}

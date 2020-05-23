#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int N;
std::vector<int> H, num_pre, min_start, max_end;
std::vector<std::vector<int>> dag, dag_inv;
std::vector<bool> vis;
std::vector<int> topo;

void toposort(int n, int p){
    if(vis[n]) return;
    vis[n] = true;
    for(int neigh : dag_inv[n])
        if(neigh != p) toposort(neigh, n);
    topo.push_back(n);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    H.resize(N);
    num_pre.resize(N);
    min_start.assign(N, 0);
    max_end.assign(N, 1000000001);
    dag.resize(N);
    dag_inv.resize(N);
    vis.assign(N, false);

    for(int i=0;i<N;i++) std::cin>>H[i];
    for(int i=0;i<N;i++){
        std::cin>>num_pre[i];
        for(int j=0;j<num_pre[i];j++){
            int pre;
            std::cin>>pre;
            dag[pre].push_back(i);
            dag_inv[i].push_back(pre);
        }
    }

    for(int i=0;i<N;i++)
        if(!vis[i]) toposort(i, -1);

    int end_t = 0;
    for(int i=0;i<N;i++){
        int ind = topo[i];
        int end = min_start[ind] + H[ind];
        for(int ch : dag[ind])
            min_start[ch] = std::max(min_start[ch], end);
        end_t = std::max(end_t, end);
        // std::cout<<ind<<": "<<min_start[ind]<<"\n";
    }
    max_end.assign(N, end_t);
    for(int i=N-1;i>=0;i--){
        int ind = topo[i];
        for(int pre : dag_inv[ind])
            max_end[pre] = std::min(max_end[pre], max_end[ind] - H[ind]);
    }
    for(int i=0;i<N;i++)
        std::cout<<(max_end[i]-H[i])<<" ";
    std::cout<<"\n";
    // std::cout<<end_t<<"\n";
}

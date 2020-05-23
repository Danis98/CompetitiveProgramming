#include <bits/stdc++.h>

typedef std::pair<int, int> ii;
typedef long long int ll;

int N, M, K;
std::vector<int> cap;
std::vector<std::vector<int>> G;

void dfs(int n, int p, int c){
    if(cap[n] != -1) return;
    cap[n] = c;
    for(int neigh : G[n])
        if(neigh != p) dfs(neigh, n, c);
}

int main(){
    std::cin>>N>>M>>K;
    cap.assign(N, -1);
    std::vector<int> caps(K);
    G.resize(N);
    for(int i=0;i<K;i++){
        std::cin>>caps[i];
        caps[i]--;
    }
    int a, b;
    for(int i=0;i<M;i++){
        std::cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<K;i++)
        dfs(caps[i], -1, caps[i]);
    std::map<int, int> freq;
    for(int i=0;i<N;i++) freq[cap[i]]++;
    int max_cap = -1, max_freq = 0;
    for(int i=0;i<K;i++)
        if(freq[caps[i]] > max_freq){
            max_freq = freq[caps[i]];
            max_cap = caps[i];
        }
    ll tot_roads = 0LL;
    ll big_nat = max_freq + freq[-1];
    tot_roads += (big_nat * (big_nat - 1)) / 2;
    for(int i=0;i<K;i++)
        if(caps[i] != max_cap)
            tot_roads += (freq[caps[i]] * (freq[caps[i]] - 1)) / 2;
    tot_roads -= M;
    std::cout<<tot_roads<<"\n";
}

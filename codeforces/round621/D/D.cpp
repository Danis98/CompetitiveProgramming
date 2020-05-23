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

    int N, M, K;
    std::cin>>N>>M>>K;
    std::vector<std::vector<int>> G(N);
    std::vector<int> S;
    std::vector<bool> is_S(N);

    for(int i=0;i<K;i++){
        int spec;
        std::cin>>spec;
        spec--;
        S.push_back(spec);
        is_S[spec] = true;
    }
    for(int i=0;i<M;i++){
        int a, b;
        std::cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int dist_from[N], dist_to[N];
    for(int i=0;i<N;i++){
        dist_from[i] = N+1;
        dist_to[i] = N+1;
    }
    dist_from[0] = 0;
    dist_to[N-1] = 0;

    std::queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int n = Q.front();
        Q.pop();
        for(int ch : G[n]){
            if(dist_from[ch] > dist_from[n] + 1){
                dist_from[ch] = dist_from[n] + 1;
                Q.push(ch);
            }
        }
    }
    Q.push(N-1);
    while(!Q.empty()){
        int n = Q.front();
        Q.pop();
        for(int ch : G[n]){
            if(dist_to[ch] > dist_to[n] + 1){
                dist_to[ch] = dist_to[n] + 1;
                Q.push(ch);
            }
        }
    }

    std::vector<iii> diff;
    for(int i : S)
        diff.push_back({dist_from[i]-dist_to[i], {dist_to[i], i}});
    std::sort(diff.begin(), diff.end());

    std::vector<int> max_to(N);
    int cur_max = -N;
    for(int i=K-1;i>=0;i--){
        max_to[diff[i].second.second] = cur_max;
        cur_max = std::max(cur_max, dist_to[diff[i].second.second]);
    }

    int res = 0;
    for(int sp : S)
        res = std::max(res, dist_from[sp] + max_to[sp] + 1);
    std::cout<<std::min(res, dist_from[N-1])<<"\n";
}

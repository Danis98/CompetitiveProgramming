#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

typedef std::pair<int, ull> iu;

int N, M;
ull V;
std::vector<ull> s;
std::vector<std::vector<iu>> G;

ull explore(int n, int p, ull d){
    ull sum = 0;
    for(auto edge : G[n]){
        int dst = edge.first;
        ull c = edge.second;
        if(dst == p || d + c > V) continue;
        sum = std::max(sum, explore(dst, n, d+c));
    }
    return sum + s[n];
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
        std::cin>>N>>M>>V;
        s.resize(N);
        for(int i=0;i<N;i++) std::cin>>s[i];
        G.resize(N);
        for(int i=0;i<M;i++){
            int a, b;
            ull c;
            std::cin>>a>>b>>c;
            G[a].push_back({b, c});
        }
    }

    std::cout<<explore(0, -1, 0)<<"\n";
}

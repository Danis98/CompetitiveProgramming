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

    int R, K, N;
    std::cin>>R>>K>>N;
    ll logR = 1;
    while(1<<logR <= R) logR++;
    std::vector<ll> g(N);
    std::vector<std::vector<ll2>> nxt(logR, std::vector<ll2>(N));
    for(int i=0;i<N;i++) std::cin>>g[i];
    for(int i=0;i<N;i++){
        ll s = 0LL;
        bool found = false;
        for(int j=0;j<N;j++){
            if(s + g[(i+j)%N] > K){ found = true; nxt[0][i] = {(i+j)%N, s}; break;}
            s += g[(i+j)%N];
        }
        if(!found) nxt[0][i] = {(i+N-1)%N, s};
    }
    for(int i=1;i<logR;i++)
        for(int j=0;j<N;j++)
            nxt[i][j] = {nxt[i-1][nxt[i-1][j].first].first, nxt[i-1][j].second + nxt[i-1][nxt[i-1][j].first].second};
    int cur = 0;
    ll res = 0LL;
    int ctr = 0;
    // for(int i=0;i<logR;i++){
    //     for(int j=0;j<N;j++)
    //         std::cout<<nxt[i][j].first<<","<<nxt[i][j].second<<" ";
    //     std::cout<<"\n";
    // }
    while(R > 0){
        if(R & 1){
            res += nxt[ctr][cur].second;
            cur = nxt[ctr][cur].first;
        }
        ctr++;
        R >>= 1;
    }
    std::cout<<res<<"\n";
}

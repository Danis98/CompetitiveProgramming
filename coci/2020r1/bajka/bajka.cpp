#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M;
    std::string A, B;
    std::cin>>N>>M>>A>>B;
    std::map<char, std::vector<int>> ch_pos;
    std::map<ll2, bool> vis;
    for(char ch='a';ch<='z';ch++) ch_pos[ch] = std::vector<int>();
    for(int i=0;i<N;i++)
        ch_pos[A[i]].pb(i);

    std::vector<std::vector<ll>> cost(M, std::vector<ll>(N, 1000000000));
    for(int p : ch_pos[B[0]])
        cost[0][p] = 0;
    for(int i=1;i<M;i++){
        for(int j=0;j<N;j++){
            if(A[j] != B[i]) continue;
            for(int p : ch_pos[B[i-1]]){
                if(j > 0 && A[j-1] == B[i-1])
                    cost[i][j] = std::min(cost[i][j], cost[i-1][p]+std::abs(p-j+1)+1);
                if(j < N-1 && A[j+1] == B[i-1])
                    cost[i][j] = std::min(cost[i][j], cost[i-1][p]+std::abs(p-j-1)+1);
            }
        }
    }

    ll res = cost[M-1][0];
    for(int i=1;i<N;i++) res = std::min(cost[M-1][i], res);
    if(res == 1000000000) std::cout<<"-1\n";
    else std::cout<<res<<"\n";

    // std::priority_queue<ll3, std::vector<ll3>, std::greater<ll3>> Q;
    // std::vector<ll> cost(M, 1000000000);
    // cost[0] = 0;
    // for(int p : ch_pos[B[0]]){
    //     Q.push({0, {0, p}});
    // }
    // while(!Q.empty()){
    //     ll3 cur = Q.top();
    //     Q.pop();
    //     ll c = cur.fi;
    //     ll idx = cur.se.fi;
    //     ll pos = cur.se.se;
    //
    //     // std::cout<<c<<" "<<idx<<" "<<pos<<" "<<A[pos]<<"\n";
    //
    //     if(idx == M-1) break;
    //
    //     if(pos > 0 && B[idx+1] == A[pos-1] && cost[idx+1] >= c+1){
    //         cost[idx+1] = c+1;
    //         Q.push({c+1, {idx+1, pos-1}});
    //         // for(int p : ch_pos[A[pos-1]]){
    //         //     if(p == pos-1) continue;
    //         //     Q.push({c+std::abs(p-pos+1)+1, {idx+1, p}});
    //         // }
    //     }
    //     if(pos < N-1 && B[idx+1] == A[pos+1] && cost[idx+1] >= c+1){
    //         cost[idx+1] = c+1;
    //         Q.push({c+1, {idx+1, pos+1}});
    //         // for(int p : ch_pos[A[pos+1]]){
    //         //     if(p == pos+1) continue;
    //         //     Q.push({c+std::abs(p-pos-1)+1, {idx+1, p}});
    //         // }
    //     }
    //     for(int p : ch_pos[A[pos]]){
    //         if(p == pos) continue;
    //         ll newc = c+std::abs(p-pos);
    //         if(cost[idx+1] <= newc+1) continue;
    //         Q.push({newc, {idx, p}});
    //     }
    // }
    //
    // if(cost[M-1] == 1000000000) std::cout<<"-1\n";
    // else std::cout<<cost[M-1]<<"\n";
}

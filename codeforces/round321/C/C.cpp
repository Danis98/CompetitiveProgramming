#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int N, M;
std::vector<int> cat, sub_free, dist;
std::vector<std::vector<int>> tree;
int res = 0;

// void dfs(int n, int p){
//     if(!cat[n]) sub_free[n] = 0;
//     else sub_free[n] = N + 1;
//     for(int ch : tree[n]){
//         if(ch == p) continue;
//         dfs(ch, n);
//         if(!cat[ch]) sub_free[n] = 0;
//         else sub_free[n] = std::min(sub_free[n], sub_free[ch] + 1);
//     }
// }
//
// int calc_res(int n, int p, int c){
//     // std::cout<<n<<" "<<c<<"\n";
//     if(tree[n].size() == 1 && n != 0) res++;
//     for(int ch : tree[n]){
//         if(ch == p) continue;
//         if(!cat[ch]) calc_res(ch, n, 0);
//         else{
//             int min_cats = c + 1;
//             if(sub_free[n] <= M - c) min_cats = std::min(min_cats, sub_free[n]+2);
//             if(min_cats <= M) calc_res(ch, n, min_cats);
//             // else std::cout<<"X "<<ch<<" "<<min_cats<<"\n";
//         }
//     }
// }

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M;
    cat.resize(N);
    tree.resize(N);
    sub_free.resize(N);
    dist.resize(N, N+1);
    for(int i=0;i<N;i++) std::cin>>cat[i];
    for(int i=0;i<N-1;i++){
        int a, b;
        std::cin>>a>>b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // dfs(0, -1);
    // calc_res(0, -1, cat[0]);
    // std::cout<<res<<"\n";

    std::queue<int> Q;
    Q.push(0);
    dist[0] = cat[0];
    while(!Q.empty()){
        int n = Q.front();
        Q.pop();
        for(int ch : tree[n]){
            int new_d;
            if(!cat[ch]) new_d = 0;
            else new_d = dist[n] + 1;
            if(dist[ch] > N && new_d <= M){
                // if(tree[ch].size() == 1 && ch != 0 && dist[ch] == N + 1) res++;
                dist[ch] = new_d;
                Q.push(ch);
            }
        }
    }
    for(int i=1;i<N;i++) if(dist[i] != N + 1 && tree[i].size() == 1) res++;
    std::cout<<res<<"\n";
}

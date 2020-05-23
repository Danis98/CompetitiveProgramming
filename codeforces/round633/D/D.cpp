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

int N;
std::vector<std::vector<int>> tree;
std::vector<int> leaf_ch;
int par[2] = {0, 0};

void dfs_par(int n, int p, int d){
    if(tree[n].size() == 1) par[d]++;
    for(int ch : tree[n])
        if(ch != p)
            dfs_par(ch, n, 1-d);
}

void count_leafs(int n, int p){
    leaf_ch[n] = 0;
    for(int ch : tree[n]){
        if(tree[ch].size() == 1) leaf_ch[n]++;
        if(ch == p) continue;
        count_leafs(ch, n);
    }
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N;
    tree.resize(N);
    leaf_ch.resize(N);
    for(int i=0;i<N-1;i++){
        int a, b;
        std::cin>>a>>b;
        a--;
        b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    int n = 0;
    for(int i=0;i<N;i++)
        if(tree[i].size() == 1){
            n = i;
            break;
        }

    dfs_par(n, n, 0);

    if(par[1] == 0) std::cout<<"1 ";
    else std::cout<<"3 ";

    int num_max = N-1;
    for(int i=0;i<N;i++)
        if(tree[i].size() == 1)
            leaf_ch[tree[i][0]]++;
    for(int i=0;i<N;i++)
        if(leaf_ch[i] > 1) num_max -= leaf_ch[i] - 1;

    std::cout<<num_max<<"\n";
}

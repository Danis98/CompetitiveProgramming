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

int N, K;
std::vector<std::vector<int>> tree;
std::vector<int> depth, par, sub;
std::vector<bool> ind;
ll tot = 0;

int get_depth(int n, int p){
    if(n != 0) depth[n] = depth[p]+1;
    par[n] = p;
    for(int ch : tree[n])
        if(ch != p) sub[n] += get_depth(ch, n);
    return sub[n] + 1;
}

int calc_res(int n, int p){
    int ctr = 0;
    for(int ch : tree[n])
        if(ch != p) ctr += calc_res(ch, n);
    if(ind[n]) ctr++;
    else tot += ctr;
    return ctr;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N>>K;
    tree.resize(N);
    depth.assign(N, 0);
    sub.assign(N, 0);
    par.assign(N, 0);
    ind.assign(N, false);
    for(int i=0;i<N-1;i++){
        int a, b;
        std::cin>>a>>b;
        a--;
        b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    get_depth(0, -1);
    std::priority_queue<ii> leafs;
    for(int i=0;i<N;i++)
        leafs.push({depth[i]-sub[i], i});
    while(K){
        ii cur = leafs.top();
        leafs.pop();
        int v = cur.fi;
        int n = cur.se;
        if(ind[n]) continue;
        ind[n] = true;
        K--;
        tot += v;
    }

    std::cout<<tot<<"\n";
}

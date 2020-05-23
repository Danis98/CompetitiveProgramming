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

ll N;
std::vector<std::vector<ll>> tree;
std::vector<ll> used;
std::vector<ll2> moves;

void dfs(){}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N;
    tree.resize(N);
    used.resize(N);
    for(int i=0;i<N-1;i++){
        int a, b;
        std::cin>>a>>b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    dfs(0, 0);
}

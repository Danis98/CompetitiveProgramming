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

#define MOD 998244353

int N;
std::vector<std::vector<int>> tree;
std::vector<ll2> dp;

void dfs(int n, int p){
    ll ch_pres = 1;
    ll ch_abs = 1;
    for(int ch : tree[n]){
        if(n == p) continue;
        dfs(ch, n);
        ch_pres *= dp[ch].fi;
        ch_abs *= dp[ch].se;
        ch_pres %= MOD;
        ch_abs %= MOD;
    }
    dp[n] = {}
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin>>N;
    tree.resize(N);
    dp.resize(N, {-1, -1});
    for(int i=0;i<N-1;i++){
        int a, b;
        std::cin>>a>>b;
        a--;
        b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    dfs(0, 0);
    std::cout<<(dp[0].fi+dp[0].se)<<"\n";
}

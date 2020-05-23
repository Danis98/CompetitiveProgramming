#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

#define MOD 998244353LL

// max-tree, lazy prop.
struct segment_tree{
    std::vector<int> tree;
    int sz;
    segment_tree(int N){
        sz = 1;
        while(sz<N) sz <<= 1;
        tree.assign(2*sz-1, 0);
    }
    ll query(int ra, int rb){ return query(0, sz-1, ra, rb, 0); }
    int query(int a, int b, int ra, int rb, int n){
        if(b < ra || a > rb) return 0;
        if(ra <= a && b <= rb) return tree[n];
        int mid = (a + b) / 2;
        return std::max(query(a, mid, ra, rb, 2*n+1),
                        query(mid+1, b, ra, rb, 2*n+2));
    }
    void update(int p, ll v){ update(0, sz-1, p, v, 0); }
    void update(int a, int b, int p, int v, int n){
        if(b < p || a > p) return;
        if(a == b){
            tree[n] = v;
            return;
        }
        int mid = (a + b) / 2;
        update(a, mid, p, v, 2*n+1),
        update(mid+1, b, p, v, 2*n+2);
        tree[n] = std::max(tree[2*n+1], tree[2*n+2]);
    }
};

ll fact[200003], fact_inv[200003];

ll choose(ll n, ll m){
    return (((fact[n] * fact_inv[m]) % MOD) * fact_inv[n-m]) % MOD;
}

ll modinv(ll a){
    ll ans = 1;
    ll m = MOD;
    for(m-=2;m;m>>=1 , a*=a , a%=MOD)
      if(m&1)
        ans*=a,ans%=MOD;
      return ans;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M;
    std::cin>>N>>M;
    ll res = 0;

    fact[0] = fact[1] = 1;
    for(int i=2;i<M;i++)
        fact[i] = (fact[i-1] * i) % MOD;
    for(int i=0;i<M;i++)
        fact_inv[i] = modinv(fact[i]);

    ll p2 = 1;
    for(int i=0;i<N-3;i++) p2 = (2 * p2) % MOD;

    for(int i=N-1;i<=M;i++){
        res += ((((choose(i-1, N-2) % MOD) * (N-2)) % MOD) * p2) % MOD;
        res %= MOD;
    }
    std::cout<<res<<"\n";
}

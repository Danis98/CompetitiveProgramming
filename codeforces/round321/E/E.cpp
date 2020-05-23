#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

#define G 127
#define DENOM 7936508LL
#define MOD 1000000007

std::vector<ll> powG;

// max-tree, lazy prop.
struct segment_tree{
    std::vector<ll> tree, lazy;
    int sz;
    segment_tree(int N){
        sz = 1;
        while(sz<N) sz <<= 1;
        tree.assign(2*sz-1, 0);
        lazy.assign(2*sz-1, -1);
    }
    ll query(int a, int b, int ra, int rb, int n){
        if(lazy[n] != -1){
            tree[n] = (lazy[n] * ((powG[b+1-a]+MOD-1)%MOD * DENOM)%MOD)%MOD;
            if(a != b){
                lazy[2*n+1] = lazy[n];
                lazy[2*n+2] = lazy[n];
            }
            lazy[n] = -1;
        }
        if(b < ra || a > rb) return 0;
        if(ra <= a && b <= rb) return tree[n];
        int mid = (a + b) / 2;
        ll r = (query(a, mid, ra, rb, 2*n+1) +
                (powG[std::max(0, mid-std::max(ra, a)+1)] * query(mid+1, b, ra, rb, 2*n+2))%MOD)%MOD;
        return r;
    }
    ll query(int ra, int rb){ return query(0, sz-1, ra, rb, 0); }
    void update(int a, int b, int ra, int rb, ll v, int n){
        if(lazy[n] != -1){
            tree[n] = (lazy[n] * ((powG[b+1-a]+MOD-1)%MOD * DENOM)%MOD)%MOD;
            if(a != b){
                lazy[2*n+1] = lazy[n];
                lazy[2*n+2] = lazy[n];
            }
            lazy[n] = -1;
        }
        if(b < ra || a > rb) return;
        if(ra <= a && b <= rb){
            tree[n] = (v * ((powG[b+1-a]+MOD-1)%MOD * DENOM)%MOD)%MOD;
            lazy[n] = -1;
            if(a != b){
                lazy[2*n+1] = v;
                lazy[2*n+2] = v;
            }
            return;
        }
        int mid = (a + b) / 2;
        update(a, mid, ra, rb, v, 2*n+1);
        update(mid+1, b, ra, rb, v, 2*n+2);
        tree[n] = (tree[2*n+1] + (powG[mid-a+1] * tree[2*n+2]) % MOD)%MOD;
    }
    void update(int ra, int rb, ll v){ update(0, sz-1, ra, rb, v, 0); }
};


int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N, M, K, Q;
    std::cin>>N>>M>>K;
    Q = M + K;
    powG.push_back(1);
    for(int i=1;i<=N;i++)
        powG.push_back((powG[i-1] * G) % MOD);
    segment_tree seg(N);
    for(int i=0;i<N;i++){
        char ch;
        std::cin>>ch;
        seg.update(i, i, ch-'0');
    }
    // for(int i=0;i<seg.tree.size();i++) std::cout<<seg.tree[i]<<" ";
    // std::cout<<"\n";
    // for(int i=0;i<seg.tree.size();i++) std::cout<<seg.lazy[i]<<" ";
    // std::cout<<"\n";
    for(int i=0;i<Q;i++){
        int t, l, r, c;
        std::cin>>t>>l>>r>>c;
        l--;
        r--;
        if(t == 1){
            seg.update(l, r, c);
        }
        else if(t == 2){
            // std::cout<<seg.query(l+c, r)<<" vs "<<seg.query(l, r-c)<<"\n";
            if(seg.query(l+c, r) == seg.query(l, r-c))
                std::cout<<"YES\n";
            else std::cout<<"NO\n";
        }
        // for(int i=0;i<seg.tree.size();i++) std::cout<<seg.tree[i]<<" ";
        // std::cout<<"\n";
        // for(int i=0;i<seg.tree.size();i++) std::cout<<seg.lazy[i]<<" ";
        // std::cout<<"\n";
    }
}

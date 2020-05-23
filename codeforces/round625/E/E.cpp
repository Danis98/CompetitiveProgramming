#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;

// max-tree, lazy prop.
struct segment_tree{
    std::vector<ll> tree, lazy;
    int sz;
    segment_tree(int N){
        sz = 1;
        while(sz<N) sz <<= 1;
        tree.assign(2*sz-1, -1e10);
        lazy.assign(2*sz-1, 0);
    }
    ll query(int ra, int rb){ return query(0, sz-1, ra, rb, 0); }
    ll query(int a, int b, int ra, int rb, int n){
        if(lazy[n] != 0){
            tree[n] += lazy[n];
            if(a != b){
                lazy[2*n+1] = lazy[n];
                lazy[2*n+2] = lazy[n];
            }
            lazy[n] = 0;
        }
        if(b < ra || a > rb) return -1e10;
        if(ra <= a && b <= rb) return tree[n];
        int mid = (a + b) / 2;
        return std::max(query(a, mid, ra, rb, 2*n+1),
                        query(mid+1, b, ra, rb, 2*n+2));
    }
    void update(int ra, int rb, ll v){ update(0, sz-1, ra, rb, v, 0); }
    void update(int a, int b, int ra, int rb, ll v, int n){
        if(lazy[n] != 0){
            tree[n] += lazy[n];
            if(a != b){
                lazy[2*n+1] = lazy[n];
                lazy[2*n+2] = lazy[n];
            }
            lazy[n] = 0;
        }
        if(b < ra || a > rb) return;
        if(ra <= a && b <= rb){
            tree[n] += v;
            lazy[n] = 0;
            if(a != b){
                lazy[2*n+1] = lazy[n];
                lazy[2*n+2] = lazy[n];
            }
            return;
        }
        int mid = (a + b) / 2;
        update(a, mid, ra, rb, v, 2*n+1);
        update(mid+1, b, ra, rb, v, 2*n+2);
        tree[n] = std::max(tree[2*n+1], tree[2*n+2]);
    }
};


int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);
    std::vector<ll2> weap(N), arm(M);
    std::vector<ll3> mons(P);
    segment_tree seg(M);
    for(int i=0;i<N;i++) scanf("%lld %lld", &weap[i].first, &weap[i].second);
    for(int i=0;i<M;i++) scanf("%lld %lld", &arm[i].first, &arm[i].second);
    for(int i=0;i<P;i++) scanf("%lld %lld %lld", &mons[i].first, &mons[i].second.first, &mons[i].second.second);
    std::sort(weap.begin(), weap.end());
    std::sort(arm.begin(), arm.end());
    std::sort(mons.begin(), mons.end());
    // for(int b=seg.sz;b>0;b>>=1){
    //     for(int i=0;i<b;i++){
    //         int idx = b-1+i;
    //         // std::cout<<idx<<"\n";
    //         if(i >= M) continue;
    //         if(2*idx+1 >= 2*seg.sz-1)seg.tree[idx] = -arm[i].second;
    //         else seg.tree[idx] = std::max(seg.tree[2*idx+1], seg.tree[2*idx+2]);
    //     }
    // }
    for(int i=0;i<M;i++) seg.update(i, i, 1e10-arm[i].second);
    // for(int i=0;i<2*seg.sz-1;i++) std::cout<<seg.tree[i]<<" ";
    // std::cout<<"\n";
    std::priority_queue<ll3, std::vector<ll3>, std::greater<ll3>> Q;
    for(int i=0;i<N;i++)
        Q.push({weap[i].first, {-1, weap[i].second}});
    for(int i=0;i<P;i++)
        Q.push({mons[i].first, {mons[i].second.first, mons[i].second.second}});
    ll res = -1e10;
    while(!Q.empty()){
        ll3 cur = Q.top();
        Q.pop();
        ll def = cur.second.first;
        ll cost = cur.second.second;
        // for(int i=0;i<2*seg.sz-1;i++) std::cout<<seg.tree[i]<<" ";
        // std::cout<<"\n";
        if(def == -1){
            // std::cout<<"Weapon for "<<cost<<"\n";
            res = std::max(res, seg.query(0, M-1) - cost);
            // std::cout<<"q="<<seg.query(0, M-1)<<"\n";
            // std::cout<<"Max is "<<res<<"\n";
            continue;
        }
        int idx = std::upper_bound(arm.begin(), arm.end(), def, [](ll a, ll2 b){
            return a < b.first;
        }) - arm.begin();
        if(idx < M){
            // std::cout<<"Adding "<<cost<<" to ["<<idx<<", "<<(M-1)<<")\n";
            seg.update(idx, M-1, cost);
        }
    }
    printf("%lld\n", res);
}

// max-tree
struct segment_tree{
    std::vector<ll> tree;
    int sz;
    segment_tree(int N){
        sz = 1;
        while(sz<N) sz <<= 1;
        tree.assign(2*sz-1, 0);
    }
    ll query(int ra, int rb){ return query(0, sz-1, ra, rb, 0); }
    ll query(int a, int b, int ra, int rb, int n){
        if(b < ra || a > rb) return 0;
        if(ra <= a && b <= rb) return tree[n];
        int mid = (a + b) / 2;
        return std::max(query(a, mid, ra, rb, 2*n+1), query(mid+1, b, ra, rb, 2*n+2));
    }
    void update(int p, ll v){ update(0, sz-1, p, v, 0); }
    void update(int a, int b, int p, ll v, int n){
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

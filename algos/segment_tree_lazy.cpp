// max-tree, lazy prop.
struct segment_tree{
    std::vector<int> tree, lazy;
    int sz;
    segment_tree(int N){
        sz = 1;
        while(sz<N) sz <<= 1;
        tree.assign(2*sz-1, 0);
        lazy.assign(2*sz-1, -1);
    }
    ll query(int ra, int rb){ return query(0, sz-1, ra, rb, 0); }
    int query(int a, int b, int ra, int rb, int n){
        if(lazy[n] != -1){
            tree[n] = lazy[n];
            if(a != b){
                lazy[2*n+1] = lazy[n];
                lazy[2*n+2] = lazy[n];
            }
            lazy[n] = -1;
        }
        if(b < ra || a > rb) return 0;
        if(ra <= a && b <= rb) return tree[n];
        int mid = (a + b) / 2;
        return std::max(query(a, mid, ra, rb, 2*n+1),
                        query(mid+1, b, ra, rb, 2*n+2));
    }
    void update(int ra, int rb, ll v){ update(0, sz-1, ra, rb, v, 0); }
    void update(int a, int b, int ra, int rb, int v, int n){
        if(lazy[n] != -1){
            tree[n] = lazy[n];
            if(a != b){
                lazy[2*n+1] = lazy[n];
                lazy[2*n+2] = lazy[n];
            }
            lazy[n] = -1;
        }
        if(b < ra || a > rb) return;
        if(ra <= a && b <= rb){
            tree[n] = v;
            lazy[n] = -1;
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

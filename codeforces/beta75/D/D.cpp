#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

// max-tree
struct segment_tree{
    std::vector<ll> tree;
    int sz;
    segment_tree(int N){
        sz = 1;
        while(sz<N) sz <<= 1;
        tree.assign(2*sz-1, -1);
    }
    ll query(int ra, int rb){ return query(0, sz-1, ra, rb, 0); }
    ll query(int a, int b, int ra, int rb, int n){
        if(b < ra || a > rb) return -1;
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


int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin>>N;
    std::vector<ll2> a(N);
    for(int i=0;i<N;i++){
        std::cin>>a[i].fi;
        a[i].se = i;
    }
    std::sort(a.begin(), a.end());
    
    segment_tree seg(N);
    std::vector<int> disp(N, -1);
    for(int i=0;i<N;i++){
        int pos = a[i].se;
        if(pos != N-1){
            ll res = seg.query(pos+1, N-1);
            if(res != -1) disp[pos] = res - pos - 1;
        }
        seg.update(pos, pos);
    }

    for(int i=0;i<N;i++) std::cout<<disp[i]<<" ";
    std::cout<<"\n";
}

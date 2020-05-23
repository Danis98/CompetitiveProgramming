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
        return query(a, mid, ra, rb, 2*n+1) + query(mid+1, b, ra, rb, 2*n+2);
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
        tree[n] = tree[2*n+1] + tree[2*n+2];
    }
};


int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    scanf("%d", &N);
    std::vector<ll> a(N), b(N);
    std::vector<ll> score(N), score2(N);
    for(int i=0;i<N;i++) scanf("%lld", &a[i]);
    for(int i=0;i<N;i++) scanf("%lld", &b[i]);

    for(int i=0;i<N;i++){
        score[i] = a[i]-b[i];
        score2[i] = -score[i];
    }

    std::set<ll> s2_vals;
    for(int i=0;i<N;i++) s2_vals.insert(score2[i]);
    segment_tree seg(s2_vals.size());

    ll tot = 0;
    for(int i=0;i<N;i++){
        int s1_pos = std::distance(s2_vals.begin(), s2_vals.lower_bound(score[i]));
        int s2_pos = std::distance(s2_vals.begin(), s2_vals.lower_bound(-score[i]));
        // std::cout<<score[i]<<" "<<s2_pos<<"\n";
        if(s1_pos > 0){
            tot += seg.query(0, s1_pos-1);
            // std::cout<<"Adding "<<seg.query(0, s1_pos)<<"\n";
        }
        seg.update(s2_pos, seg.tree[seg.sz-1+s2_pos] + 1);
        // std::cout<<score[i]<<"["<<s1_pos<<" "<<s2_pos<<"]\n";
        // for(int j=0;j<2*seg.sz-1;j++) std::cout<<seg.tree[j]<<" ";
        // std::cout<<"\n";
    }
    printf("%lld\n", tot);
}

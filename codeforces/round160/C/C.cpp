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

    int M, N;
    std::cin>>M;
    std::vector<int> q(M);
    for(int i=0;i<M;i++) std::cin>>q[i];
    std::cin>>N;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];

    std::sort(q.begin(), q.end());
    std::sort(a.begin(), a.end());

    std::vector<ll> pre(N);
    pre[0] = a[0];
    for(int i=1;i<N;i++) pre[i] = pre[i-1] + a[i];

    int to_buy = N;
    ll disc = 0;
    while(to_buy > 0){
        if(q[0] > to_buy){
            disc += pre[to_buy-1];
            to_buy = 0;
        }
        else{
            if(q[0] == to_buy)
                disc += pre[to_buy-1];
            else
                disc += pre[to_buy-1] - pre[to_buy-q[0]-1];
            to_buy -= q[0] + 2;
        }
    }
    std::cout<<disc<<"\n";
}

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

// max-tree, no lazy
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
        return query(a, mid, ra, rb, 2*n+1) +
                        query(mid+1, b, ra, rb, 2*n+2);
    }
    void update(int p, ll v){ update(0, sz-1, p, v, 0); }
    void update(int a, int b, int p, ll v, int n){
        if(p < a || p > b) return;
        if(a == b){
            tree[n] = v;
            return;
        }
        int mid = (a + b) / 2;
        update(a, mid, p, v, 2*n+1);
        update(mid+1, b, p, v, 2*n+2);
        tree[n] = tree[2*n+1] + tree[2*n+2];
    }
};


int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N;
    std::cin>>N;
    std::vector<ll2> a(N);
    std::vector<ll> pos(N);
    for(int i=0;i<N;i++) std::cin>>a[i].second;
    for(int i=0;i<N;i++) std::cin>>a[i].first;
    std::sort(a.begin(), a.end(), [](ll2 a, ll2 b){
        return a.second < b.second;
    });
    segment_tree sum(N), mask(N);
    for(int i=0;i<N;i++){
        sum.update(i, a[i].second);
        mask.update(i, 1);
        pos[i] = a[i].second;
        a[i].second = i;
    }
    std::sort(a.begin(), a.end());
    ll res = 0LL;
    for(int i=0;i<N;i++){
        ll v = a[i].first;
        int ind = a[i].second;
        res += sum.query(ind+1, N) - mask.query(ind+1, N) * pos[ind];
        sum.update(ind, 0);
        mask.update(ind, 0);
    }
    std::cout<<res<<"\n";
}

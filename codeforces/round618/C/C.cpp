#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

struct SegmentTree{
    int t[400000];

    void init(){
        memset(t, 0, sizeof(t));
    }

    void modify(int a, int b, int p, int value, int pos){
        if(p < a || b < p) return;
        if(a == b){
            t[pos] = value;
            return;
        }
        int mid = (a+b)/2;
        modify(a, mid, p, value, 2*pos+1);
        modify(mid+1, b, p, value, 2*pos+2);
        t[pos] = t[2*pos+1] | t[2*pos+2];
    }

    int query(int a, int b, int qa, int qb, int pos){
        // std::cout<<a<<" "<<b<<"\n";
        int res = 0;
        if(b < qa || qb < a) return 0;
        if(qa <= a && b <= qb) return t[pos];
        int mid = (a+b)/2;
        res |= query(a, mid, qa, qb, 2*pos+1);
        res |= query(mid+1, b, qa, qb, 2*pos+2);
        return res;
    }
};

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N;
    std::vector<int> A;
    std::cin>>N;
    A.resize(N);
    for(int i=0;i<N;i++) std::cin>>A[i];
    SegmentTree seg;
    seg.init();
    int p = 1;
    while(p < N) p <<= 1;
    for(int i=0;i<N;i++) seg.modify(0, p-1, i, A[i], 0);
    // for(int i=0;i<2*p-1;i++) std::cout<<seg.t[i]<<" ";
    // std::cout<<"\n";
    int imax = -1, vmax = -1;
    for(int i=0;i<N;i++){
        int rest = 0;
        if(i > 0) rest |= seg.query(0, p-1, 0, i-1, 0);
        if(i < N-1) rest |= seg.query(0, p-1, i+1, N-1, 0);
        // std::cout<<rest<<"\n";
        int val = A[i] & (~rest);
        // std::cout<<A[i]<<" "<<val<<" "<<imax<<" "<<vmax<<"\n";
        if(vmax == -1 || val > vmax){imax = i; vmax = val;}
    }
    std::cout<<A[imax]<<" ";
    for(int i=0;i<N;i++) if(i != imax) std::cout<<A[i]<<" ";
    std::cout<<"\n";
}

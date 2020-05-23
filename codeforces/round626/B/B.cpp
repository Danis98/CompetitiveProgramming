#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M, K;
    std::cin>>N>>M>>K;
    std::vector<int> a(N), b(M);
    for(int i=0;i<N;i++) std::cin>>a[i];
    for(int i=0;i<M;i++) std::cin>>b[i];

    std::vector<int> w_v, h_v;
    int ctr = 0;
    for(int i=0;i<N;i++){
        if(a[i] == 1) ctr++;
        else if(ctr != 0) {
            w_v.push_back(ctr);
            ctr = 0;
        }
    }
    if(a[N-1] == 1) w_v.push_back(ctr);
    ctr = 0;
    for(int i=0;i<M;i++){
        if(b[i] == 1) ctr++;
        else if(ctr != 0) {
            h_v.push_back(ctr);
            ctr = 0;
        }
    }
    if(b[M-1] == 1) h_v.push_back(ctr);

    ll res = 0;
    for(int r_w = 1;r_w<=N;r_w++){
        if(K % r_w != 0) continue;
        ll h_pos = 0, v_pos = 0;
        for(int w : w_v)
            if(w >= r_w)
                h_pos += w - r_w + 1;
        for(int h : h_v)
            if(h >= K / r_w)
                v_pos += h - K / r_w + 1;
        res += h_pos * v_pos;
    }

    std::cout<<res<<"\n";
}

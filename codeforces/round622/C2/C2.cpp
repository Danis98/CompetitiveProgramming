#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

struct min_queue{
    std::deque<ll2> Q;
    int start=0, end=0;
    void add(ll v){
        while(!Q.empty() && Q.back().second >= v) Q.pop_back();
        Q.push_back({end++, v});
    }
    ll2 prev_min(){
        ll2 b = Q.back();
        Q.pop_back();
        if(Q.empty()){
            Q.push_back(b);
            return {-1, -1};
        }
        ll2 res = Q.back();
        Q.push_back(b);
        return res;
    }
};

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N;
    std::cin>>N;
    std::vector<ll> A(N);
    for(int i=0;i<N;i++) std::cin>>A[i];

    std::vector<ll> lslope(N), rslope(N);

    min_queue dir;
    for(int i=0;i<N;i++){
        dir.add(A[i]);
        ll2 m = dir.prev_min();
        if(m.first == -1) lslope[i] = (i+1) * A[i];
        else lslope[i] = lslope[m.first] + (i-m.first) * A[i];
        // std::cout<<lslope[i]<<"\n";
    }
    min_queue inv;
    int ctr = 0;
    for(int i=N-1;i>=0;i--){
        inv.add(A[i]);
        ll2 m = inv.prev_min();
        // std::cout<<ctr<<" "<<m.first<<" "<<m.second<<"\n";
        if(m.first == -1) rslope[i] = (ctr+1) * A[i];
        else rslope[i] = rslope[N-m.first-1] + (ctr-m.first) * A[i];
        ctr++;
        // std::cout<<rslope[i]<<"\n";
    }

    ll max_val=0, res_idx = -1;
    for(int i=0;i<N;i++){
        ll score = lslope[i] + rslope[i] - A[i];
        if(max_val < score){
            res_idx = i;
            max_val = score;
        }
    }

    std::vector<int> out(N);
    out[res_idx] = A[res_idx];
    ll min_so_far = A[res_idx];
    for(int j=res_idx-1;j>=0;j--){
        min_so_far = std::min(A[j], min_so_far);
        out[j] = min_so_far;
    }
    min_so_far = A[res_idx];
    for(int j=res_idx+1;j<N;j++){
        min_so_far = std::min(A[j], min_so_far);
        out[j] = min_so_far;
    }

    for(int i=0;i<N;i++)
        std::cout<<out[i]<<" ";
    std::cout<<"\n";
}

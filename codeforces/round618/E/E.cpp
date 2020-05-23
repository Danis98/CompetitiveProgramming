#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

typedef std::pair<double, int> di;

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
    std::vector<ull> A;
    std::cin>>N;
    A.resize(N);
    for(int i=0;i<N;i++) std::cin>>A[i];
    std::vector<ull> pre(N);
    pre[0] = A[0];
    for(int i=1;i<N;i++) pre[i] = pre[i-1] + A[i];

    std::stack<di> S;
    S.push({A[0], 1});
    double avg;
    for(int i=1;i<N;i++){
        avg = (double)(pre[i]-pre[i-1]);
        // std::cout<<S.top().first<<" "<<avg<<"\n";
        int cnt = 1;
        while(!S.empty() && S.top().first > avg){
            di p_top = S.top();
            S.pop();
            avg = (p_top.first*p_top.second+avg*cnt)/(p_top.second+cnt);
            cnt += p_top.second;
        }
        S.push({avg, cnt});
    }

    std::stack<di> S_inv;
    while(!S.empty()){
        S_inv.push(S.top());
        S.pop();
    }

    while(!S_inv.empty()){
        di t = S_inv.top();
        S_inv.pop();
        for(int i=0;i<t.second;i++) printf("%.09f\n", t.first);
    }
}

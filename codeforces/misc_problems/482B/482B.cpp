#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define BEGIN 0
#define END 1

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M;
    std::cin>>N>>M;
    std::vector<ll3> q(M);
    std::vector<ll3> e(2*M);
    for(int i=0;i<M;i++){
        ll L, R, X;
        std::cin>>L>>R>>X;
        q[i] = {L-1, {R-1, X}};
        e[2*i] = {L-1, {BEGIN, X}};
        e[2*i+1] = {R-1, {END, X}};
    }
    std::sort(e.begin(), e.end());

    std::vector<ll> res(N, 0);
    for(int b=0;b<32;b++){
        std::vector<ll> pre(N, 0);
        int nxt_e = 0, ctr = 0;
        for(int i=0;i<N;i++){
            while(nxt_e < 2*M && e[nxt_e].fi <= i){
                int bit = (e[nxt_e].se.se >> b) & 1;
                if(e[nxt_e].se.fi == BEGIN)
                    ctr += bit == 1;
                else break;
                nxt_e++;
            }

            if(i > 0) pre[i] = pre[i-1];
            if(ctr > 0){
                pre[i]++;
                res[i] |= 1 << b;
            }

            while(nxt_e < 2*M && e[nxt_e].fi <= i){
                int bit = (e[nxt_e].se.se >> b) & 1;
                if(e[nxt_e].se.fi == END)
                    ctr -= bit == 1;
                else break;
                nxt_e++;
            }
        }

        // for(int i=0;i<N;i++)
        //     std::cout<<pre[i]<<" \n"[i==N-1];

        for(int i=0;i<M;i++){
            int bit = (q[i].se.se >> b) & 1;
            if(bit == 1) continue;
            if(pre[q[i].se.fi] - (q[i].fi==0?0:pre[q[i].fi-1]) == q[i].se.fi-q[i].fi+1 && pre[q[i].fi] != 0){
                std::cout<<"NO\n";
                return 0;
            }
        }
    }
    std::cout<<"YES\n";
    for(int i=0;i<N;i++)
        std::cout<<res[i]<<" \n"[i==N-1];
}

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;

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

    int N, M, K;
    std::cin>>N>>K>>M;
    std::vector<ll3> c(2*M);
    for(int i=0;i<M;i++){
        int s, e, n;
        std::cin>>s>>e>>n;
        s--;
        e--;
        c[2*i] = {s, {BEGIN, n}};
        c[2*i+1] = {e, {END, n}};
    }
    std::sort(c.begin(), c.end());

    ll tot = 0;
    for(int k=0;k<K;k++){
        std::vector<bool> fix(N, false);
        int one_ctr = 0;
        int evt_ptr = 0;
        for(int i=0;i<N;i++){
            while(evt_ptr < 2*M && c[evt_ptr].fi == i){
                if(c[evt_ptr].se.fi == BEGIN)
                    one_ctr += (c[evt_ptr].se.se >> k) & 1;
                else break;
                evt_ptr++;
            }
            if(one_ctr > 0) fix[i] = true;
            while(evt_ptr < 2*M && c[evt_ptr].fi == i){
                if(c[evt_ptr].se.fi == END)
                    one_ctr -= (c[evt_ptr].se.se >> k) & 1;
                else break;
                evt_ptr++;
            }
        }

        std::vector<int> pre_nonfix(N, 0);
        for(int i=0;i<N;i++)
            pre_nonfix[i] = (fix[i] ? 0 : 1) + (i == 0 ? 0 : pre_nonfix[i-1]);
        
    }
}

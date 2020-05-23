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

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        ll N, K;
        std::cin>>N>>K;
        std::string S;
        std::cin>>S;
        ll tot = 0;
        std::vector<ll> mod(K, 0);
        std::vector<ll> mpre0(N, 0), mpre1(N, 0), mtot(K, 0);
        for(int i=0;i<N;i++){
            mpre0[i] = i < K ? 0 : mpre0[i-K];
            mpre1[i] = i < K ? 0 : mpre1[i-K];
            mtot[i%K]++;
            if(S[i] == '1'){
                tot++;
                mod[i%K]++;
                mpre1[i]++;
            }
            else mpre0[i]++;
        }
        std::vector<ll> bestf(N, 0);
        for(int i=N-1;i>=0;i--){
            ll f = mpre0[i] - mpre1[i] + mod[i%K];
            if(i+K < N) bestf[i] = std::min(bestf[i+K], f);
            else bestf[i] = f;
        }

        ll best = N;
        for(int i=0;i<K;i++){
            ll rest = tot - mod[i];
            ll seq = mod[i];
            for(int j=i;j<N;j+=K){
                ll v = bestf[j];
                if(j >= K) v += mpre1[j-K] - mpre0[j-K];
                seq = std::min(seq, v);
            }
            best = std::min(best, seq+rest);
        }
        std::cout<<best<<"\n";
    }
}

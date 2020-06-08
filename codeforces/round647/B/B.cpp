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

#define MOD 1000000007
#define MAXN 1000000

ll modpow(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1) res = (res * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return res;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll T;
    std::cin>>T;
    std::vector<ll> freq;
    while(T--){
        ll N, P;
        std::cin>>N>>P;
        // freq.assign(MAXN+1, 0);
        std::vector<ll> v;
        ll m = 0, s = 0;
        for(int i=0;i<N;i++){
            ll k;
            std::cin>>k;
            // freq[k]++;
            v.pb(k);
            s += v[i];
            m = std::max(v[i], m);
        }
        std::sort(v.begin(), v.end(), [](ll a, ll b){
            return a > b;
        });
        ll p = m, mul = 0;
        for(int i=0;i<N;i++){
            if(mul == 0){
                p = v[i];
                mul = 1;
            }
            else if(v[i] == p)
                mul--;
            else if(v[i] < p){
                p = v[i];
                mul = (mul * P) - 1;
            }
            std::cout<<p<<" "<<mul<<"\n";
        }
        ll diff = (modpow(P, p) * (mul%MOD)) % MOD;
        std::cout<<diff<<"\n";
    }
}

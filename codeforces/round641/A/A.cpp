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

#define MAXA 200000L
#define MOD (MAXA*MAXA)

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

    std::vector<bool> prime(MAXA+1, true);
    prime[0] = prime[1] = false;
    std::vector<ll> primes;
    for(int i=2;i<=MAXA;i++){
        if(!prime[i]) continue;
        primes.pb(i);
        for(int j=2;j*i<=MAXA;j++)
            prime[i*j] = false;
    }

    ll N;
    std::cin>>N;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    ll res = 1;
    for(ll p : primes){
        ll ctr = 0;
        for(ll v=1;v<=MAXA;v*=p){
            for(int j=0;j<N;j++){
                if(a[j] % v == 0 && a[j] % (v*p) != 0) ctr++;
                if(ctr == 2) break;
            }
            if(ctr == 2){
                // std::cout<<"["<<p<<", "<<v<<"]"<<"\n";
                res *= v;
                break;
            }
        }
    }

    std::cout<<res<<"\n";
}

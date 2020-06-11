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

#define MAXA 10000000

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll N;
    std::cin>>N;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    std::vector<bool> eras(MAXA+1, true);
    std::vector<ll> primes;
    for(int i=2;i<=std::sqrt(MAXA+1);i++){
        if(!eras[i]) continue;
        primes.pb(i);
        for(int j=i;j<=std::sqrt(MAXA);j+=i) eras[j] = false;
    }
    std::vector<ll> d1(N, -1), d2(N, -1);
    for(int i=0;i<N;i++){
        for(ll p : primes){
            if(p*p > a[i]) break;
            if(a[i] % p != 0) continue;
            while(a[i] % p == 0) a[i] /= p;
            if(a[i] != 1){
                d1[i] = p;
                d2[i] = a[i];
            }
            break;
        }
    }
    for(int i=0;i<N;i++) std::cout<<d1[i]<<" \n"[i==N-1];
    for(int i=0;i<N;i++) std::cout<<d2[i]<<" \n"[i==N-1];
}

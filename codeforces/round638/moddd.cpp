#include <bits/stdc++.h>

#define MOD 43

typedef long long ll;

std::vector<ll> fact, fact_inv;

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
    std::cout<<modpow(10, 30)<<"\n";
}
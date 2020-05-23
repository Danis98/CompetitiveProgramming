#define MOD 998244353

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

ll modinv(ll a){
	return modpow(a, MOD-2);
}

void calc_fact(ll N){
	fact.assign(N+1, 1);
	fact_inv.assign(N+1, 1);
    for(ll i=2;i<=N;i++){
        fact[i] = (fact[i-1] * i) % MOD;
        fact_inv[i] = modinv(fact[i]);
    }
}

ll bin(ll N, ll K){
	ll res = (fact[N] * fact_inv[K]) % MOD;
	res = (res * fact_inv[N-K]) % MOD;
	return res;
}

ll stirling(ll N, ll K){
	ll res = 0;
	ll minus = MOD - 1;
	for(int i=0;i<K;i++){
		ll term = (bin(K, i) * modpow(K-i, N)) % MOD;
		res = (res + modpow(MOD-1, i) * term) % MOD;
	}
	res = (res * fact_inv[K]) % MOD;
	return res;
}
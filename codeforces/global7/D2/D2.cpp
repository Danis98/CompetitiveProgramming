#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define MOD 1000000007
#define P 127

ll modpow(ll a, ll k) { // a^k % p
    ll ret = 1;
    while(k) {
        if(k % 2) ret = (ret * a) % MOD;
        k /= 2;
        a = (a * a) % MOD;
    }
    return ret;
}


ll concat_hash(ll h1, ll l1, ll h2, ll l2){
    h1 = (h1 * modpow(P, l2)) % MOD;
    return (h1 + h2) % MOD;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        std::string s;
        std::cin>>s;
        int N = s.length();

        int comm;
        for(comm=0;comm<N/2;comm++) if(s[comm] != s[N-comm-1]) break;
        int idx = comm;
        std::string cand1 = "", cand2 = "";
        // pref palyndrome
        ll h = s[comm] - 'a', hr = h;
        for(int i=comm+1;i<N-comm;i++){
            ll l = s[i] - 'a';
            // std::cout<<i<<" "<<s[i]<<" "<<l<<" "<<h<<" "<<hr<<"\n";
            if(concat_hash(h, i-comm, l, 1) == concat_hash(l, 1, hr, i-comm))
                idx = std::max(idx, i);
            h = concat_hash(h, i-comm, l, 1);
            hr = concat_hash(l, 1, hr, i-comm);
        }
        for(int i=0;i<=std::min(idx, N-comm-1);i++) cand1 += s[i];
        for(int i=std::max(idx+1, N-comm);i<N;i++) cand1 += s[i];

        // std::cout<<cand1<<" "<<cand1.length()<<"\n";

        //post palyndrome
        h = s[N-comm-1] - 'a', hr = h;
        idx = N - comm - 1;
        for(int i=N-comm-2;i>=comm;i--){
            ll l = s[i] - 'a';
            // std::cout<<i<<" "<<s[i]<<" "<<l<<" "<<h<<" "<<hr<<"\n";
            if(concat_hash(l, 1, h, (N-comm-1)-i) == concat_hash(hr, (N-comm-1)-i, l, 1))
                idx = std::min(idx, i);
            h = concat_hash(l, 1, h, (N-comm-1)-i);
            hr = concat_hash(hr, (N-comm-1)-i, l, 1);
            // std::cout<<"->"<<h<<" "<<hr<<"\n";
        }
        for(int i=0;i<comm;i++) cand2 += s[i];
        for(int i=std::max(idx, comm);i<N;i++) cand2 += s[i];

        // std::cout<<cand2<<" "<<cand2.length()<<"\n";

        if(cand1.length() > cand2.length()) std::cout<<cand1<<"\n";
        else std::cout<<cand2<<"\n";
    }
}

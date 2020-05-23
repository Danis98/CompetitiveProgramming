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

#define P 137
#define M 1000000007

std::vector<ll> Ppow;

ll modpow(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1) res = (res * a) % M;
        b >>= 1;
        a = (a * a) % M;
    }
    return res;
}

ll modinv(ll a){
	return modpow(a, M-2);
}

ll gen_ppow(ll N){
    Ppow.resize(N+1, 1);
    for(int i=1;i<=N;i++)
        Ppow[i] = (Ppow[i-1] * P) % M;
}

ll hash_create(std::string S, int begin, int end){
    ll hash = 0;
    for(int i=begin;i<=end;i++)
        hash = (P * hash + S[i]) % M;
    return hash;
}

ll hash_right_push(ll hash, char ch){
    return (P * hash + ch) % M;
}

ll hash_left_push(ll hash, char ch, int len){
    return (Ppow[len] * ch + hash) % M;
}

ll hash_right_pop(ll hash, char ch){
    return ((hash - ch + M) * modinv(P)) % M;
}

ll hash_left_pop(ll hash, int len, char ch){
    return (hash - ch * Ppow[len-1] + M) % M;
}

ll hash_shift_right(ll hash, std::string S, int beg, int len){
    return hash_right_push(hash_left_pop(hash, len, S[beg]), S[beg+len]);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string S;
    S.reserve(1000000);
    for(int i=0;i<1000000;i++){
        S[i] = getchar();
        if(S[i] == '\0') break;
    }
    ll N = S.length();

    std::cout<<S<<"\n";

    gen_ppow(N);

    int last_valid = 0;
    int pre_len = 0;
    int mid_start = 1;
    ll pre_hash = 0, mid_hash = 0, post_hash = 0;
    for(int i=0;i<N;i++){
        pre_hash = hash_right_push(pre_hash, S[i]);
        post_hash = hash_left_push(post_hash, S[N-i-1], i);
        if(mid_start >= N-i-1) break;
        mid_hash = hash_right_push(mid_hash, S[mid_start+i]);
        while(mid_start < N-i-1 && mid_hash != pre_hash)
            mid_hash = hash_shift_right(mid_hash, S, mid_start++, i+1);
        if(mid_start >= N-i-1) break;
        // std::cout<<i<<" "<<mid_start<<", "<<pre_hash<<" "<<mid_hash<<" "<<post_hash<<std::endl;
        if(pre_hash == post_hash && pre_hash == mid_hash)
            last_valid = i+1;
    }

    if(last_valid == 0)
        std::cout<<"Just a legend\n";
    else{
        for(int i=0;i<last_valid;i++)
            putchar(S[i]);
        putchar('\n');
    }
}

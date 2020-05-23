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

#define MOD 1000000000

ll3 get_disp(std::string S, int idx){
    ll2 disp = {0, 0};
    while(idx != S.length() && S[idx] != ')'){
        if(S[idx] == 'N') disp.se = (disp.se - 1 + MOD) % MOD;
        else if(S[idx] == 'S') disp.se = (disp.se + 1) % MOD;
        else if(S[idx] == 'W') disp.fi = (disp.fi - 1 + MOD) % MOD;
        else if(S[idx] == 'E') disp.fi = (disp.fi + 1) % MOD;
        else{
            ll times = S[idx] - '0';
            ll3 res = get_disp(S, idx+2);
            idx = res.fi;
            disp.fi = (disp.fi + times * res.se.fi) % MOD;
            disp.se = (disp.se + times * res.se.se) % MOD;
        }
        idx++;
    }
    return {idx, disp};
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++){
        std::cout<<"Case #"<<t<<": ";
        std::string S;
        std::cin>>S;
        ll3 fin = get_disp(S, 0);
        std::cout<<fin.se.fi+1LL<<" "<<fin.se.se+1LL<<"\n";
    }
}

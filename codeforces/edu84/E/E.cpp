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

#define MOD 998244353

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin>>N;

    std::vector<ll> poss(N, 1);
    for(int i=1;i<N;i++) poss[i] = (poss[i-1] * 10) % MOD;

    std::vector<ll> num(N+1, 0);
    for(int i=1;i<=N;i++){
        if(i == N) num[i] = 10;
        else{
            num[i] = (2LL*10LL*9LL*poss[N-i-1]) % MOD;
            num[i] = (num[i] + 10LL*(N-i-1LL)*9LL*9LL*poss[(N-i-2)]) % MOD;
        }
        std::cout<<num[i]<<" ";
    }
    std::cout<<"\n";
}

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
        std::vector<ll> dp(N, 0);
        for(int i=1;i<N;i++) dp[i] = dp[i-1] + i;
        std::string s = "";
        for(int i=0;i<N;i++) s += 'a';
        int f_pos = 1, s_pos = 0;
        for(int i=1;i<N;i++){
            f_pos = i;
            if(dp[i] >= K) break;
        }
        s_pos = f_pos - (dp[f_pos] - K) - 1;

        s[N-f_pos-1] = 'b';
        s[N-s_pos-1] = 'b';

        std::cout<<s<<"\n";
    }
}

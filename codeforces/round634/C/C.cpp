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
        int N;
        std::cin>>N;
        std::vector<ll> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        std::map<ll, ll> freq;
        for(ll ab : a) freq[ab]++;
        ll skill_num = 0;
        for(auto sk : freq) skill_num++;
        ll sol = 0;
        for(int i=1;i<=N;i++){
            sol = std::max(sol, std::min(freq[i], skill_num-1));
            sol = std::max(sol, std::min(freq[i]-1, skill_num));
        }
        std::cout<<sol<<"\n";
    }
}

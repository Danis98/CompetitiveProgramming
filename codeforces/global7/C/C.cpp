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

#define MOD 998244353

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N, K;
    std::cin>>N>>K;
    std::vector<ll2> a(N);
    for(int i=0;i<N;i++){
        std::cin>>a[i].fi;
        a[i].se = i;
    }
    std::sort(a.begin(), a.end());
    std::reverse(a.begin(), a.end());

    std::vector<ll> pos(K);
    ll max_v = 0;
    for(int i=0;i<K;i++){
        max_v += a[i].fi;
        pos[i] = a[i].se;
    }
    std::sort(pos.begin(), pos.end());

    ll tot = 1;
    for(int i=0;i<K-1;i++)
        tot = (tot * (pos[i+1] - pos[i])) % MOD;

    std::cout<<max_v<<" "<<tot<<"\n";
}

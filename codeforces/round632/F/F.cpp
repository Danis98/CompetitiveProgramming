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

#define MAXN 500000

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<bool> pres(MAXN, true);
    ll N;
    std::cin>>N;
    std::vector<int> a(N+1);
    ll v = N / 2, num_v = std::min(N / v, v) - 1;
    pres[v] = false;
    for(int i=N;i>=2;i--){
        if(v == 1){
            a[i] = 1;
            continue;
        }
        if(num_v == 0){
            while(!pres[v]) v--;
            pres[v] = false;
            num_v = std::min(N / v, v) - 1;
            for(int j=2;j<=std::sqrt(v);j++) if(v % j == 0) pres[j] = false;
        }
        a[i] = v;
        num_v--;
    }
    for(int i=2;i<=N;i++)
        std::cout<<a[i]<<" ";
    std::cout<<"\n";
}

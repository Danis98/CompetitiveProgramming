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

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin>>N;
    std::vector<ll> b(N);
    for(int i=0;i<N;i++) std::cin>>b[i];
    std::vector<ll> a(N);
    ll m = 0;
    for(int i=0;i<N;i++){
        a[i] = m + b[i];
        m = std::max(a[i], m);
    }
    for(int i=0;i<N;i++) std::cout<<a[i]<<" ";
    std::cout<<"\n";
}

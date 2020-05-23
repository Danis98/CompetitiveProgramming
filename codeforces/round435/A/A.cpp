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

#define MAXV 100

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll N, X;
    std::cin>>N>>X;
    std::vector<ll> a(MAXV+1, 0);
    for(int i=0;i<N;i++){
        ll t;
        std::cin>>t;
        a[t] = 1;
    }
    ll moves = 0;
    for(int i=0;i<X;i++)
        moves += 1 - a[i];
    moves += a[X];
    std::cout<<moves<<"\n";
}

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

    int N;
    std::cin>>N;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    std::vector<ll> res(N, 0);
    for(int b=0;b<20;b++){
        ll bitf = 0;
        for(int i=0;i<N;i++) bitf += (a[i]>>b) & 1;
        for(int i=0;i<bitf;i++)
            res[i] |= 1 << b;
    }
    ll S = 0;
    for(ll s : res) S += s * s;
    std::cout<<S<<"\n";
}

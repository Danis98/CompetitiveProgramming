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

    int N, M;
    std::cin>>N>>M;
    std::vector<ll> a(M);
    for(int i=0;i<M;i++) std::cin>>a[i];
    std::sort(a.begin(), a.end());
    ll res = a[N-1] - a[0];
    for(int i=1;i<=M-N;i++)
        res = std::min(res, a[i+N-1]-a[i]);
    std::cout<<res<<"\n";
}

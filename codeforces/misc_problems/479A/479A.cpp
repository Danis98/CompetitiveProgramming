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

    ll A, B, C;
    std::cin>>A>>B>>C;
    ll r1 = A+B+C;
    ll r2 = (A+B)*C;
    ll r3 = A+(B*C);
    ll r4 = (A*B)+C;
    ll r5 = A*(B+C);
    ll r6 = A*B*C;
    ll res = std::max(std::max(std::max(r1, r2), std::max(r3, r4)), std::max(r5, r6));
    std::cout<<res<<"\n";
}

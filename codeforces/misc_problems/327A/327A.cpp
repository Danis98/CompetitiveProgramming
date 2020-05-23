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

    ll N;
    std::cin>>N;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    std::vector<ll> pre(N);
    pre[0] = 1-2*a[0];
    ll cnt = a[0];
    ll res = pre[0];
    for(int i=1;i<N;i++){
        pre[i] = pre[i-1] + 1-2*a[i];
        res = std::max(res, pre[i]);
        cnt += a[i];
    }

    for(int i=0;i<N;i++)
        for(int j=0;j<i;j++)
            res = std::max(res, pre[i]-pre[j]);

    std::cout<<cnt+res<<"\n";
}

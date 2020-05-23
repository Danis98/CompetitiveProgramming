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

    ll N, A, B, C;
    std::cin>>N>>A>>B>>C;

    ll res = 0;
    for(int i=0;A*i<=N;i++)
        for(int j=0;A*i+B*j<=N;j++){
            if((N - A*i - B*j) % C != 0) continue;
            res = std::max(res, i+j+(N-A*i-B*j)/C);
        }
    std::cout<<res<<"\n";
}

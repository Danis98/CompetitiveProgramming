#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll N, M, K;
    std::cin>>N>>M>>K;
    std::vector<ll> a(N);
    std::vector<ll> b(M);
    for(int i=0;i<N;i++) std::cin>>a[i];
    for(int i=0;i<M;i++) std::cin>>b[i];

    int i = 0, j = 0;
    while(i < N && a[i] % K == 0) i++;
    while(j < M && b[j] % K == 0) j++;
    // std::cout<<i<<" "<<j<<" "<<(i+j)<<"\n";

    std::cout<<(i+j)<<"\n";
}

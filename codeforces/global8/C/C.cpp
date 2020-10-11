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
    ll K = 8 + N * 7;
    std::cout<<K<<"\n";
    std::vector<ll2> p(7);
    p[0] = {0, 1};
    p[1] = {0, 2};
    p[2] = {1, 0};
    p[3] = {1, 2};
    p[4] = {2, 0};
    p[5] = {2, 1};
    p[6] = {2, 2};
    std::cout<<"0 0\n";
    for(int i=0;i<=N;i++)
        for(int j=0;j<7;j++)
            std::cout<<(p[j].fi+i*2)<<" "<<(p[j].se+i*2)<<"\n";
}

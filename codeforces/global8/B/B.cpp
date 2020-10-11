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
    std::string S = "codeforces";
    ll L = S.length();
    std::vector<ll> v(L, std::floor(std::pow(N, 1.0/L)));
    ll P = std::pow(v[0], L);
    for(int i=0;i<L;i++)
        if(P >= N) break;
        else{
            P /= v[i];
            v[i]++;
            P *= v[i];
        }
    for(int i=0;i<10;i++)
        for(int j=0;j<v[i];j++)
            std::cout<<S[i];
    std::cout<<"\n";
}

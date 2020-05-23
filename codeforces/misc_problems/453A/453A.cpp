#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;
typedef long double ld;

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

    ld N, M;
    std::cin>>M>>N;

    ld prob = 1.0/M;
    std::vector<ld> cum_prob(M+1, 0), max_prob(M+1, 0);
    for(int i=1;i<=M;i++){
        cum_prob[i] = std::pow(prob * i, N);
        max_prob[i] = cum_prob[i] - cum_prob[i-1];
    }
    ld e = 0;
    for(int i=1;i<=M;i++)
        e += i * max_prob[i];
    std::cout<<e<<"\n";
}

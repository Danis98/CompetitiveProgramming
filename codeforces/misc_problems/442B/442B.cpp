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

    ll N;
    std::cin>>N;
    std::vector<ld> p(N);
    for(int i=0;i<N;i++) std::cin>>p[i];

    std::sort(p.begin(), p.end());

    if(p[N-1] == 1.0){
        std::cout<<"1.0\n";
        return 0;
    }

    ld best = 0;
    ld P = 1, S = 0;
    for(int i=N-1;i>=0;i--){
        P *= 1 - p[i];
        S += p[i]/(1-p[i]);
        best = std::max(best, P*S);
    }

    std::cout<<std::setprecision(10)<<best<<"\n";
}

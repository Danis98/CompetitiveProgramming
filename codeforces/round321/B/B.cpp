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

    int N;
    ll d;
    std::cin>>N>>d;
    std::vector<ll2> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i].first>>a[i].second;
    std::sort(a.begin(), a.end());
    int start = 0, end = 0;
    ll tot_s = a[0].second, max_s = tot_s;
    for(int i=1;i<N;i++){
        end = i;
        tot_s += a[i].second;
        while(a[end].first >= a[start].first + d)
            tot_s -= a[start++].second;
        max_s = std::max(tot_s, max_s);
    }
    std::cout<<max_s<<"\n";
}

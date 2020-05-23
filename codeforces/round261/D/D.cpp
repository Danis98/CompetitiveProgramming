#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
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

    int N;
    std::cin>>N;
    std::vector<ll> a(N);
    std::unordered_map<ll, int> freq, pre;
    for(int i=0;i<N;i++){
        std::cin>>a[i];
        freq[a[i]]++;
    }

    ll res = 0, add = 0;
    std::vector<ll> less_than(N+1, N);
    less_than[1] = N;
    std::vector<ll> tri(N+1, 0);
    for(int i=1;i<N;i++) tri[i] = i + tri[i-1];
    for(int i=0;i<N;i++){
        ll post = freq[a[i]] - pre[a[i]];
        ll more_than = N - less_than[post];
        res += add - more_than * tri[post];
        std::cout<<post<<" "<<add<<" "<<more_than<<"\n";
        less_than[pre[a[i]]]--;
        pre[a[i]]++;
        add += pre[a[i]];
    }
    std::cout<<res<<"\n";
}

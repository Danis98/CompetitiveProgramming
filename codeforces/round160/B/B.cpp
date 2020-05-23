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

    int N, K;
    std::cin>>N>>K;
    std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
    for(int i=0;i<N;i++){
        int t;
        std::cin>>t;
        Q.push(t);
    }

    for(int i=0;i<K;i++){
        int m = Q.top();
        Q.pop();
        Q.push(-m);
    }

    ll tot = 0;
    for(int i=0;i<N;i++){
        int m = Q.top();
        Q.pop();
        tot += m;
    }

    std::cout<<tot<<"\n";
}

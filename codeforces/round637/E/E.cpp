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

    ll N, M;
    std::cin>>N>>M;
    std::vector<ll> a(M);
    for(int i=0;i<M;i++) std::cin>>a[i];
    std::sort(a.begin(), a.end());
    ll G, R;
    std::cin>>G>>R;
    for(int i=0;i<M-1;i++)
        if(a[i+1] - a[i] > G){
            std::cout<<"-1\n";
            return 0;
        }

    std::vector<std::vector<ll>> dist(M, std::vector<ll>(G, 10000000000LL));
    std::priority_queue<ll2, std::vector<ll2>, std::greater<ll2>> Q;
    Q.push({0, 0});
    dist[0][0] = 0;
    ll res = -1;
    while(!Q.empty()){
        ll2 cur = Q.top();
        Q.pop();
        ll d = cur.fi, n = cur.se;
        // std::cout<<"["<<d<<" "<<n<<"]\n";
        if(a[n] == N){
            res = d;
            break;
        }
        for(int i=n;i<N;i++){
            ll newd = d + a[i] - a[n];
            if(newd/G > d/G && (newd != G*(d/G+1))) break;
            if(dist[i][newd%G] <= newd) continue;
            dist[i][newd%G] = newd;
            Q.push({newd, i});
        }
        for(int i=n;i>=0;i--){
            ll newd = d + a[n] - a[i];
            if(newd/G > d/G && (newd != G*(d/G+1))) break;
            if(dist[i][newd%G] <= newd) continue;
            dist[i][newd%G] = newd;
            Q.push({newd, i});
        }
    }
    if(res != -1) res += R * (res / G);
    std::cout<<res<<"\n";
}

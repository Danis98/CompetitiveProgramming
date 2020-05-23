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

    int T;
    std::cin>>T;
    while(T--){
        ll N, K;
        std::cin>>N>>K;
        std::vector<ll> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];

        std::vector<ll> pre(N, 0);
        for(int i=1;i<N-1;i++){
            pre[i] = pre[i-1];
            if(a[i] > a[i-1] && a[i] > a[i+1]) pre[i]++;
        }

        ll res = 0, l = -1;
        for(int i=0;i<=N-K;i++){
            ll score = pre[i+K-2]-pre[i]+1;
            if(score > res){
                res = score;
                l = i+1;
            }
        }
        std::cout<<res<<" "<<l<<"\n";
    }
}

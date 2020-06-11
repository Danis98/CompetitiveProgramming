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
    std::vector<ll> a(N), b(M);
    for(int i=0;i<N;i++) std::cin>>a[i];
    for(int i=0;i<M;i++) std::cin>>b[i];
    ll res = 1, ctr = 0;
    std::vector<ll> seg_end(M, -1);
    ll cur_b = 0, min_start = 0;
    while(a[min_start] != b[0]) min_start++;
    for(int i=min_start;i<N;i++){
        if(a[i] < b[0]){
            res = 0;
            break;
        }
        // ll p1 = 0, p2 = N-1;
        // while(p1<p2){
        //     ll m = (p1+p2)/2;
        //     if(b[m] > a[i]) p2 = m;
        //     else p1 = m+1;
        // }
        // if(p1 <= cur_b){
        //     cur_b = p1;
        //     ctr = 0;
        //     min_start =
        // }
    }
    std::cout<<res<<"\n";
}

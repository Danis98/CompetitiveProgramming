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

    int N, M;
    std::cin>>N>>M;
    std::vector<int> l(M);
    for(int i=0;i<M;i++) std::cin>>l[i];
    ll s = 0;
    for(int i=0;i<M;i++) s += l[i];
    if(s < N){
        std::cout<<"-1\n";
        return 0;
    }
    for(int i=0;i<M;i++)
        if(N-l[i] < i){
            std::cout<<"-1\n";
            return 0;
        }
    // std::vector<ll2> v;
    std::vector<int> p(M);
    // for(int i=0;i<M;i++) v.pb({l[i], i});
    // std::sort(v.begin(), v.end());
    // std::reverse(v.begin(), v.end());
    // for(int i=0;i<M;i++){
    //     p[v[i].se] = i;
    // }
    //
    // for(int i=0;i<M;i++) std::cout<<p[i]<<" ";
    // std::cout<<"\n";
    //
    // int e = N-1;
    // for(int i=M-1;i>=1;i--){
    //     if(p[i]+l[i] < e){
    //         p[i] = e - l[i];
    //         e = p[i]-1;
    //     }
    //     else break;
    // }

    for(int i=0;i<M;i++) p[i] = i;

    // for(int i=0;i<M;i++) std::cout<<p[i]<<" ";
    // std::cout<<"\n";

    int e = N-1;
    for(int i=M-1;i>=1;i--){
        // std::cout<<i<<" "<<(p[i]+l[i]-1)<<" "<<e<<"\n";
        if(p[i]+l[i]-1 < e){
            p[i] = e - l[i] + 1;
            e = p[i]-1;
        }
        else break;
    }

    for(int i=0;i<M;i++) std::cout<<p[i]+1<<" ";
    std::cout<<"\n";
}

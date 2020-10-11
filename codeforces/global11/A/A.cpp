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
        int N;
        std::cin>>N;
        std::vector<ll> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        std::vector<ll> b;
        ll s = 0;
        for(int i=0;i<N;i++){
            if(a[i] != 0) b.pb(a[i]);
            s += a[i];
        }
        if(s == 0){
            std::cout<<"NO\n";
            continue;
        }
        std::cout<<"YES\n";
        std::sort(b.begin(), b.end());
        if(s > 0) std::reverse(b.begin(), b.end());
        for(int i=0;i<b.size();i++) std::cout<<b[i]<<" ";
        for(int i=0;i<N-b.size();i++) std::cout<<"0 ";
        std::cout<<"\n";
    }
}

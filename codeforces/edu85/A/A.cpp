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
        std::vector<ll2> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i].fi>>a[i].se;
        bool valid = a[0].fi >= a[0].se;
        for(int i=1;i<N;i++){
            if(a[i].fi < a[i-1].fi || a[i].se < a[i-1].se || a[i].fi < a[i].se){
                valid = false;
                break;
            }
            ll d = a[i].fi - a[i-1].fi;
            if(a[i].se - a[i-1].se > d){
                valid = false;
                break;
            }
        }
        if(valid) std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
}

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
    for(int t=1;t<=T;t++){
        std::cout<<"Case #"<<t<<": ";
        ll N, D;
        std::cin>>N>>D;
        std::vector<ll> x(N);
        for(int i=0;i<N;i++) std::cin>>x[i];
        ll a = 1, b = D;
        while(a < b){
            ll mid = (a+b+1)/2;
            ll ctr = mid;
            for(int i=0;i<N;i++){
                ll d = ctr / x[i];
                if(ctr % x[i] != 0) d++;
                ctr = d * x[i];
            }
            if(ctr > D) b = mid - 1;
            else a = mid;
        }
        std::cout<<a<<"\n";
    }
}

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
        bool pres = false;
        for(int i=0;i<N;i++) pres |= a[i] != -1;
        if(!pres){
            std::cout<<"0 42\n";
            continue;
        }
        ll min = 1000000000, max = 0;
        ll m = 0;
        for(int i=0;i<N;i++){
            if(a[i] == -1){
                if(i != 0 && a[i-1] != -1){
                    min = std::min(min, a[i-1]);
                    max = std::max(max, a[i-1]);
                }
                if(i != N-1 && a[i+1] != -1){
                    min = std::min(min, a[i+1]);
                    max = std::max(max, a[i+1]);
                }
            }
            else{
                if(i != 0 && a[i-1] != -1)
                    m = std::max(m, std::abs(a[i]-a[i-1]));
            }
            // std::cout<<"["<<a[i]<<" "<<min<<" "<<max<<" "<<m<<"]\n";
        }
        ll k = (min+max)/2;
        m = std::max(m, std::max(max-k, k-min));
        std::cout<<m<<" "<<k<<"\n";
    }
}

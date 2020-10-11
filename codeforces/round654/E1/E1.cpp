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

    ll N, P;
    std::cin>>N>>P;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    std::sort(a.begin(), a.end());
    std::vector<ll> sol;
    for(ll x=a[0];x<=a[N-1];x++){
        bool fin = true;
        for(int i=0;i<N;i++)
            if(x+i<a[i]){
                fin = false;
                break;
            }
        if(!fin) continue;
        bool good = true;
        for(int i=0;i<N;i++){
            if((i+1-std::max(0LL, a[i]-x))%P == 0){
                good = false;
                break;
            }
            // std::cout<<"["<<x<<" "<<(i+1-std::max(0LL, a[i]-x))<<"]\n";
        }
        if(good) sol.pb(x);
    }
    std::cout<<sol.size()<<"\n";
    for(int i=0;i<sol.size();i++)
        std::cout<<sol[i]<<" \n"[i==sol.size()-1];
}

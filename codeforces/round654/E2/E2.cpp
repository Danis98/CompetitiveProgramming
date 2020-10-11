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
    std::vector<ll> sol, cand;
    ll xmin = a[0];
    for(int i=0;i<N;i++)
        if(a[i]>xmin+i-1)
            xmin = a[i] - i;
    bool poss = true;
    for(int i=0;i<N;i++)
        if(a[i] <= xmin && (i+1)%P == 0)
            poss = false;
    if(!poss){
        std::cout<<"0\n";
        return 0;
    }
    std::vector<ll> modmax(P, a[N-1]);
    for(int i=0;i<N;i++){
        ll m = (a[i]-i-1+P)%P;
        for(int p=0;p<P;p++)
            if(p!=m) modmax[p] = std::min(a[i]-1, modmax[p]);
    }
    for(ll x=xmin;x<=a[N-1];x++){
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

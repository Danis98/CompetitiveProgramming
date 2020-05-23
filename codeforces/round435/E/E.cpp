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

    ll N, M, Q;
    std::cin>>N>>M>>Q;
    std::vector<ll> a(N), b(M);
    for(int i=0;i<N;i++) std::cin>>a[i];
    for(int i=0;i<M;i++) std::cin>>b[i];

    ll alpha = 0;
    for(int i=0;i<N;i++)
        alpha += (i%2?-1:1) * a[i];

    std::vector<ll> beta;
    ll cur = 0;
    for(int i=0;i<N;i++)
        cur += (i%2?-1:1) * b[i];
    beta.pb(cur);
    for(int j=0;j<M-N;j++){
        cur -= (j%2?-1:1) * b[j];
        cur *= -1;
        cur += ((j+N+1)%2?-1:1) * b[j+N];
        beta.pb(cur);
    }
    std::sort(beta.begin(), beta.end());

    ll l = 0, r = beta.size()-1;
    while(l<r){
        int mid = (l+r)/2;
        if(beta[mid] <= alpha) r = mid;
        else l = mid+1;
    }
    ll r1 = std::abs(alpha-beta[l]);
    if(l == N-1) std::cout<<r1<<"\n";
    else std::cout<<std::min(r1, std::abs(alpha-beta[l+1]))<<"\n";

    for(int i=0;i<Q;i++){
        ll a, b, v;
        std::cin>>a>>b>>v;
        if((b-a+1)%2 == 1)
            alpha += (a%2?1:-1) * v;
        std::cout<<"a: "<<alpha<<"\n";
        ll l = 0, r = beta.size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if(alpha <= beta[mid]) r = mid;
            else l = mid+1;
        }
        std::cout<<"b: "<<beta[l]<<"\n";
        ll r1 = std::abs(alpha-beta[l]);
        if(l == 0) std::cout<<r1<<"\n";
        else std::cout<<std::min(r1, std::abs(alpha-beta[l-1]))<<"\n";
    }
}

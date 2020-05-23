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

    ll A, B, C, D;
    std::cin>>A>>B>>C>>D;
    ll res = 0;
    for(ll x=A;x<=B;x++){
        ll minY = std::max(B, std::min(C+1-x, C));
        ll maxY = C;
        ll minS = x+minY;
        ll maxS = x+maxY;
        // std::cout<<" ["<<x<<" "<<minS<<" "<<maxS<<"]\n";
        ll delta = 0;
        if(minS <= D){
            if(maxS > C) delta += (std::min(maxS, D)-C)*(std::min(maxS, D)-C+1)/2;
            // std::cout<<"["<<delta<<" ";
            if(minS > C+1) delta -= (minS-C)*(minS-C-1)/2;
            // std::cout<<delta<<" ";
        }
        if(maxS > D) delta += (D-C+1)*(maxS-std::max(D, minS-1));
        // std::cout<<delta<<"]\n";
        res += delta;
        // for(ll s=minS;s<=maxS;s++){
        //     res += std::min(s-C, D-C+1);
        // }
    }
    std::cout<<res<<"\n";
}

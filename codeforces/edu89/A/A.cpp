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
        ll A, B;
        std::cin>>A>>B;
        if(A == 0 || B == 0){
            std::cout<<"0\n";
            continue;
        }
        ll x = (2*A-B)/3;
        ll y = (-A+2*B)/3;
        // std::cout<<"["<<x<<" "<<y<<"]\n";
        if(x <= 0) std::cout<<std::min(A, B/2)<<"\n";
        else if(y <= 0) std::cout<<std::min(A/2, B)<<"\n";
        else std::cout<<(A+B)/3<<"\n";
    }
}

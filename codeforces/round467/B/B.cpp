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

    ll P, Y;
    std::cin>>P>>Y;
    bool found = false;
    for(int i=Y;i>P;i--){
        bool valid = true;
        for(int j=2;j<=std::min((double)P, std::sqrt(i));j++)
            if(i % j == 0){
                valid = false;
                break;
            }
        if(valid){
            found = true;
            std::cout<<i<<"\n";
            break;
        }
    }
    if(!found) std::cout<<"-1\n";
}

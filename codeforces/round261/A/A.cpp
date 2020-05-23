#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
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

    int x1, y1, x2, y2;
    std::cin>>x1>>y1>>x2>>y2;
    if(y1 == y2){
        int l = x2 - x1;
        std::cout<<x1<<" "<<(y1+l)<<" "<<x2<<" "<<(y2+l)<<"\n";
    }
    else if(x1 == x2){
        int l = y2 - y1;
        std::cout<<(x1+l)<<" "<<y1<<" "<<(x2+l)<<" "<<y2<<"\n";
    }
    else{
        if(std::abs(x2 - x1) == std::abs(y2 - y1))
            std::cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<"\n";
        else std::cout<<"-1\n";
    }
}

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
        ll a, b, c, d;
        std::cin>>a>>b>>c>>d;
        ll x, y, x1, y1, x2, y2;
        std::cin>>x>>y>>x1>>y1>>x2>>y2;

        bool xok = true, yok = true;
        if(a+b == 0) xok = true;
        else{
            ll endx = x + b - a;
            if(endx >= x1 && endx <= x2 && x2-x1 > 0) xok = true;
            else xok = false;
        }
        if(c+d == 0) yok = true;
        else{
            ll endy = y + d - c;
            if(endy >= y1 && endy <= y2 && y2-y1 > 0) yok = true;
            else yok = false;
        }

        if(xok && yok) std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
}

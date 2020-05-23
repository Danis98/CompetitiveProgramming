#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int V, A, R, P, H;
    std::cin>>V>>A>>R>>P>>H;
    int S = V + A + R + P;
    if(S - V < H && S - A < H && S - R < H && S - P < H) std::cout<<"AWW\n";
    else std::cout<<"WAW\n";
}

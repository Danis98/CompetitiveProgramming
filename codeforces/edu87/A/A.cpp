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
        ll A, B, C, D;
        std::cin>>A>>B>>C>>D;
        if(A <= B){
            std::cout<<B<<"\n";
            continue;
        }
        else if(C <= D){
            std::cout<<"-1\n";
            continue;
        }
        ll rem = A - B;
        ll cycs = rem / (C-D) + (rem%(C-D)==0?0:1);
        std::cout<<(B+cycs*C)<<"\n";
    }
}

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

    int N;
    ll g1, g2, g3, g4, g5, g6;
    ll e1, e2, e3, e4, e5, e6, e7;
    std::cin>>N;
    for(int i=0;i<N;i++){
        std::cin>>g1>>g2>>g3>>g4>>g5>>g6;
        std::cin>>e1>>e2>>e3>>e4>>e5>>e6>>e7;
        ll gscore = g1 + 2*g2 + 3*g3 + 3*g4 + 4*g5 + 10*g6;
        ll escore = e1 + 2*e2 + 2*e3 + 2*e4 + 3*e5 + 5*e6 + 11*e7;
        std::cout<<"Battle "<<(i+1)<<": ";
        if(gscore > escore) std::cout<<"Good triumphs over Evil\n";
        else if(gscore == escore) std::cout<<"No victor on this battle field\n";
        else std::cout<<"Evil eradicates all trace of Good\n";
    }
}

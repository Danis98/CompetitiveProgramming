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

    int N;
    std::cin>>N;
    for(int i=0;i<=N/2;i++){
        for(int j=0;j<N/2-i;j++) std::cout<<"*";
        for(int j=0;j<2*i+1;j++) std::cout<<"D";
        for(int j=0;j<N/2-i;j++) std::cout<<"*";
        std::cout<<"\n";
    }
    for(int i=N/2-1;i>=0;i--){
        for(int j=0;j<N/2-i;j++) std::cout<<"*";
        for(int j=0;j<2*i+1;j++) std::cout<<"D";
        for(int j=0;j<N/2-i;j++) std::cout<<"*";
        std::cout<<"\n";
    }
}

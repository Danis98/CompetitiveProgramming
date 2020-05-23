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

    int N, M;
    std::cin>>N>>M;
    for(int i=0;i<N;i++){
        if(i%2 == 0)
            for(int j=0;j<M;j++) std::cout<<"#";
        else if(i%4 == 1){
            for(int j=0;j<M-1;j++) std::cout<<".";
            std::cout<<"#";
        }
        else if(i%4 == 3){
            std::cout<<"#";
            for(int j=0;j<M-1;j++) std::cout<<".";
        }
        std::cout<<"\n";
    }
}

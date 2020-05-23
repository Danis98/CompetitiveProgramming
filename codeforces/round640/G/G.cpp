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
        ll N;
        std::cin>>N;
        if(N <= 3){
            std::cout<<"-1\n";
            continue;
        }
        if(N == 4){
            std::cout<<"3 1 4 2\n";
            continue;
        }
        if(N == 8){
            std::cout<<"1 3 6 8 5 7 4 2\n";
            continue;
        }

        int start = 1;
        if(N%2 == 0){
            std::cout<<"2 4 1 5 3 ";
            start = 6;
        }

        for(int i=start;i<=N;i+=2)
            std::cout<<i<<" ";
        ll cur = N;
        if(cur-3 > start)
            std::cout<<cur-3<<" "<<cur-1<<" ";
        for(int i=cur-5;i>=start;i-=2)
            std::cout<<i<<" ";
        std::cout<<"\n";
    }
}

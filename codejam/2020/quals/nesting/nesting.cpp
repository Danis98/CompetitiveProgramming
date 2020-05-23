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
    for(int t=1;t<=T;t++){
        std::string S;
        std::cin>>S;
        std::cout<<"Case #"<<t<<": ";
        int ctr = 0;
        for(char ch : S){
            int d = ch - '0';
            while(d > ctr) {ctr++; std::cout<<"(";}
            while(d < ctr) {ctr--; std::cout<<")";}
            std::cout<<d;
        }
        for(int i=0;i<ctr;i++) std::cout<<")";
        std::cout<<"\n";
    }
}

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

    ll N, S;
    std::cin>>N>>S;
    if(N == 1){
        if(S == 1) std::cout<<"NO\n";
        else std::cout<<"YES\n"<<S<<"\n1\n";
        return 0;
    }
    if(2*N > S){
        std::cout<<"NO\n";
        return 0;
    }

    std::cout<<"YES\n";
    for(int i=0;i<N-1;i++){
        std::cout<<"2 ";
        S -= 2;
    }
    std::cout<<S<<"\n";
    std::cout<<"1\n";
}

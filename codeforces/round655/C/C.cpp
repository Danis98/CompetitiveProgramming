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

    ll T;
    std::cin>>T;
    while(T--){
        ll N;
        std::cin>>N;
        std::vector<ll> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        bool ord = true, same = false;
        ll s = 0, e = N-1;
        while(s<N && a[s] == s+1) s++;
        while(e>=0 && a[e] == e+1) e--;
        for(int i=s;i<=e;i++){
            if(a[i] == i+1) same = true;
            else ord = false;
        }
        if(ord) std::cout<<"0\n";
        else if(!same) std::cout<<"1\n";
        else std::cout<<"2\n";
    }
}

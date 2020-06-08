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
        std::vector<ll> a(N), b(N);
        for(int i=0;i<N;i++)
            std::cin>>a[i];
        for(int i=0;i<N;i++)
            std::cin>>b[i];
        bool mono = true;
        for(int i=1;i<N;i++)
            mono &= b[i] == b[0];
        if(!mono){
            std::cout<<"Yes\n";
            continue;
        }
        bool ord = true;
        for(int i=1;i<N;i++)
            ord &= a[i] >= a[i-1];
        if(ord) std::cout<<"Yes\n";
        else std::cout<<"No\n";
    }
}

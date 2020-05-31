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
        ll N, X;
        std::cin>>N>>X;
        std::vector<ll> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        ll odd = 0, even = 0;
        for(int i=0;i<N;i++)
            if(a[i]%2==1) odd++;
            else even++;
        bool found = false;
        for(int i=0;i<=std::min(even, X);i++)
            if((X-i)%2==1 && (X-i) <= odd){
                found = true;
                break;
            }
        if(found) std::cout<<"Yes\n";
        else std::cout<<"No\n";
    }
}

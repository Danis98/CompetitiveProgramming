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
        for(int i=0;i<N;i++) std::cin>>a[i];
        for(int i=0;i<N;i++) std::cin>>b[i];

        if(N%2 && a[N/2] != b[N/2]){
            std::cout<<"No\n";
            continue;
        }
        std::vector<ll2> p1, p2;
        for(int i=0;i<N/2;i++){
            if(a[i]>a[N-i-1]) std::swap(a[i], a[N-i-1]);
            if(b[i]>b[N-i-1]) std::swap(b[i], b[N-i-1]);
            p1.pb({a[i], a[N-i-1]});
            p2.pb({b[i], b[N-i-1]});
        }
        std::sort(p1.begin(), p1.end());
        std::sort(p2.begin(), p2.end());

        bool eq = true;
        for(int i=0;i<N/2;i++)
            eq &= p1[i] == p2[i];
        if(eq) std::cout<<"Yes\n";
        else std::cout<<"No\n";
    }
}

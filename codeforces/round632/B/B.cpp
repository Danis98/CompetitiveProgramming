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
        int N;
        std::cin>>N;
        std::vector<ll> a(N), b(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        for(int i=0;i<N;i++) std::cin>>b[i];
        bool plus = false, minus = false, valid = true;
        for(int i=0;i<N;i++){
            if(a[i] > b[i] && !minus){ valid = false; break; }
            if(a[i] < b[i] && !plus){ valid = false; break; }
            if(a[i] > 0) plus = true;
            if(a[i] < 0) minus = true;
        }
        std::cout<<(valid?"YES":"NO")<<"\n";
    }
}

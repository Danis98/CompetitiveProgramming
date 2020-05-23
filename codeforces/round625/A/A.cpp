#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N;
    std::cin>>N;
    std::vector<int> a(N), b(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    for(int i=0;i<N;i++) std::cin>>b[i];
    int sA = 0, sB = 0;
    for(int i=0;i<N;i++){
        if(a[i] == b[i]) continue;
        sA += a[i];
        sB += b[i];
    }
    if(sA == 0){
        std::cout<<"-1\n";
        return 0;
    }
    int req = sB + 1;
    int res = req / sA;
    if(req % sA != 0) res++;
    std::cout<<res<<"\n";
}

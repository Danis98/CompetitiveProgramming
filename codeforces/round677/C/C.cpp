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
        std::vector<int> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        int max = -1;
        for(int i=0;i<N;i++) max = std::max(max, a[i]);
        int idx = -1;
        for(int i=0;i<N;i++){
            if(a[i] < max) continue;
            if(i > 0 && a[i-1] < a[i] || i < N-1 && a[i+1] < a[i]){
                idx = i + 1;
                break;
            }
        }
        std::cout<<idx<<"\n";
    }
}

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
        if(N%4 != 0){
            std::cout<<"NO\n";
            continue;
        }
        std::cout<<"YES\n";
        std::vector<ll> a(N, 0);
        for(int i=0;i<N/2;i++){
            a[i] = 2*(i+1);
            a[N-1] += a[i];
        }
        for(int i=N/2;i<N-1;i++){
            a[i] = 2*(i-N/2)+1;
            a[N-1] -= a[i];
        }
        for(int i=0;i<N;i++)
            std::cout<<a[i]<<" \n"[i==N-1];
    }
}

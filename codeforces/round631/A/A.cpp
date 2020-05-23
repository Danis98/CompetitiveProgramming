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

#define MAXV 200

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        int N, X;
        std::cin>>N>>X;
        std::vector<bool> a(MAXV+2, false);
        for(int i=0;i<N;i++){
            int t;
            std::cin>>t;
            a[t] = true;
        }
        int res = 200;
        for(int i=1;i<=MAXV;i++){
            if(!a[i]){
                if(X > 0) X--;
                else{
                    res = i-1;
                    break;
                }
            }
        }
        std::cout<<res<<"\n";
    }
}

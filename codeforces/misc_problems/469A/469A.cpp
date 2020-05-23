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

    int N;
    std::cin>>N;
    std::vector<bool> lev(N);
    int P, Q;
    std::cin>>P;
    for(int i=0;i<P;i++){
        int l;
        std::cin>>l;
        lev[l-1] = true;
    }
    std::cin>>Q;
    for(int i=0;i<Q;i++){
        int l;
        std::cin>>l;
        lev[l-1] = true;
    }
    for(int i=0;i<N;i++)
        if(!lev[i]){
            std::cout<<"Oh, my keyboard!\n";
            return 0;
        }
    std::cout<<"I become the guy.\n";
}

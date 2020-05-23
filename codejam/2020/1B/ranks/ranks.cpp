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
    for(int t=1;t<=T;t++){
        int R, S;
        std::cin>>R>>S;
        std::vector<ii> moves;
        for(int i=0;i<S-1;i++){
            for(int j=0;j<=i;j++){
                moves.pb({R*(S-j-1), R-1});
            }
        }
        std::cout<<moves.size()<<"\n";
        for(ii move : moves)
            std::cout<<move.fi<<" "<<move.se<<"\n";
    }
}

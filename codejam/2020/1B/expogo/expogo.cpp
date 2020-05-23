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

ll manhattan(ll x1, ll y1, ll x2, ll y2){
    return std::abs(x1-x2) + std::abs(y1-y2);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++){
        std::cout<<"Case #"<<t<<": ";
        ll X, Y;
        std::cin>>X>>Y;
        ll d = std::abs(X) + std::abs(Y);
        int p = 1;
        while((1LL<<(p))-1 < d) p++;
        bool valid = true;
        std::string moves = "";
        while(p){
            ll dist = manhattan(0, 0, X, Y);
            if(dist % 2 == 0){
                valid = false;
                break;
            }
            if(manhattan(1LL<<(p-1), 0, X, Y) <= (1LL<<(p-1))-1){
                X -= 1LL<<(p-1);
                moves = "E" + moves;
            }
            else if(manhattan(0, 1LL<<(p-1), X, Y) <= (1LL<<(p-1))-1){
                Y -= 1LL<<(p-1);
                moves = "N" + moves;
            }
            else if(manhattan(-(1LL<<(p-1)), 0, X, Y) <= (1LL<<(p-1))-1){
                X += 1LL<<(p-1);
                moves = "W" + moves;
            }
            else if(manhattan(0, -(1LL<<(p-1)), X, Y) <= (1LL<<(p-1))-1){
                Y += 1LL<<(p-1);
                moves = "S" + moves;
            }
            p--;
        }
        if(valid) std::cout<<moves<<"\n";
        else std::cout<<"IMPOSSIBLE\n";
    }
}

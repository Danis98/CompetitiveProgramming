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

    int N, M, K;
    std::cin>>N>>M>>K;
    int minX = N, maxX = 0, minY = M, maxY = 0;
    for(int i=0;i<K;i++){
        int x, y;
        std::cin>>x>>y;
        minX = std::min(minX, x);
        maxX = std::max(maxX, x);
        minY = std::min(minY, y);
        maxY = std::max(maxY, y);
    }
    ll move_n = maxX - 1 + maxY - 1;
    // std::cout<<"["<<minX<<" "<<maxX<<" "<<minY<<" "<<maxY<<"]\n";
    std::vector<ll2> f(K);
    for(int i=0;i<K;i++) std::cin>>f[i].fi>>f[i].se;
    std::sort(f.begin(), f.end());
    ll2 cur_pos = {1, 1};
    std::string moves = "";
    for(int i=1;i<maxX;i++) moves += "U";
    for(int i=1;i<maxY;i++) moves += "L";
    for(int i=0;i<K;i++){
        ll fx = f[i].fi, fy = f[i].se;
        if(fx > cur_pos.fi){
            for(int j=cur_pos.fi;j<fx;j++){
                move_n++;
                moves += "D";
            }
        }
        else if(fx < cur_pos.fi){
            for(int j=fx;j<cur_pos.fi;j++){
                move_n++;
                moves += "U";
            }
        }
        // std::cout<<"["<<fy<<" "<<cur_pos.se<<"]\n";
        if(fy > cur_pos.se){
            for(int j=cur_pos.se;j<fy;j++){
                move_n++;
                moves += "R";
            }
        }
        else if(fy < cur_pos.se){
            for(int j=fy;j<cur_pos.se;j++){
                move_n++;
                moves += "L";
            }
        }
        cur_pos = f[i];
    }
    std::cout<<move_n<<"\n";
    std::cout<<moves<<"\n";
}

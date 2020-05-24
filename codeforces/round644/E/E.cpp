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
        std::vector<std::string> grid(N);
        for(int i=0;i<N;i++) std::cin>>grid[i];

        bool valid = true;
        for(int i=0;i<N-1;i++)
            for(int j=0;j<N-1;j++)
                if(grid[i][j] == '1' && grid[i+1][j] == '0' && grid[i][j+1] == '0')
                    valid = false;
        if(valid) std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
}

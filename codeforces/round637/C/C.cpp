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
        std::vector<ll> p(N);
        for(int i=0;i<N;i++) std::cin>>p[i];

        ll cur_max = p[N-1], cur_pos = N-1, cur_min = 1;
        bool valid = true;
        for(int i=N-1;i>=0;i--){
            if(p[i] != cur_max + i - cur_pos){
                valid = false;
                break;
            }
            if(p[i] == cur_min && i != 0){
                cur_min = cur_max + 1;
                cur_pos = i - 1;
                cur_max = p[i-1];
            }
        }

        if(valid) std::cout<<"Yes\n";
        else std::cout<<"No\n";
    }
}

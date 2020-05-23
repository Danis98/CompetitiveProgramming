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
        std::vector<bool> d_taken(N, false), p_taken(N, false);
        for(int i=0;i<N;i++){
            int d;
            std::cin>>d;
            for(int j=0;j<d;j++){
                int prince;
                std::cin>>prince;
                prince--;
                if(!d_taken[i] && !p_taken[prince])
                    d_taken[i] = p_taken[prince] = true;
            }
        }
        int d = -1, p = -1;
        for(int i=0;i<N;i++)
            if(!d_taken[i]){
                d = i;
                break;
            }
        for(int i=0;i<N;i++)
            if(!p_taken[i]){
                p = i;
                break;
            }
        if(d == -1 || p == -1) std::cout<<"OPTIMAL\n";
        else std::cout<<"IMPROVE\n"<<d+1<<" "<<p+1<<"\n";
    }
}

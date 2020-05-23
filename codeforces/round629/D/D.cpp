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
        std::vector<ll> t(N);
        for(int i=0;i<N;i++) std::cin>>t[i];
        bool same_adj = false, all_same = true;
        int same_p = 0;
        for(int i=0;i<N;i++)
            if(t[i] == t[(i+1) % N]){
                same_adj = true;
                same_p = (i+1)%N;
            }
            else all_same = false;
        if(all_same){
            std::cout<<"1\n";
            for(int i=0;i<N;i++) std::cout<<"1 ";
            std::cout<<"\n";
        }
        else{
            std::vector<ll> c(N);
            if(same_adj || N%2 == 0) std::cout<<"2\n";
            else std::cout<<"3\n";
            for(int i=0;i<N;i++){
                int col = 1 + (i % 2);
                if(i == N-1){
                    if(t[(same_p+i)%N] != t[(same_p+i+1)%N] && col == 1)
                        col = 3;
                }
                c[(same_p+i)%N] = col;
            }
            for(int i=0;i<N;i++) std::cout<<c[i]<<" ";
            std::cout<<"\n";
        }
    }
}

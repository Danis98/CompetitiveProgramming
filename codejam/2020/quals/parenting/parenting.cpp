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

#define END 0
#define START 1

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++){
        int N;
        std::cin>>N;
        std::vector<iii> evt(2*N);
        for(int i=0;i<N;i++){
            std::cin>>evt[2*i].fi;
            evt[2*i].se = {START, i};
            std::cin>>evt[2*i+1].fi;
            evt[2*i+1].se = {END, i};
        }
        std::sort(evt.begin(), evt.end());
        std::vector<char> ass(N);
        bool c_occ = false, j_occ = false;
        bool poss = true;
        for(int i=0;i<2*N;i++){
            iii e = evt[i];
            if(e.se.fi == START){
                if(!c_occ){
                    ass[e.se.se] = 'C';
                    c_occ = true;
                }
                else if(!j_occ){
                    ass[e.se.se] = 'J';
                    j_occ = true;
                }
                else{
                    poss = false;
                    break;
                }
            }
            else if(e.se.fi == END){
                if(ass[e.se.se] == 'C') c_occ = false;
                else if(ass[e.se.se] == 'J') j_occ = false;
            }
        }
        std::cout<<"Case #"<<t<<": ";
        if(poss)
            for(int i=0;i<N;i++) std::cout<<ass[i];
        else std::cout<<"IMPOSSIBLE";
        std::cout<<"\n";
    }
}

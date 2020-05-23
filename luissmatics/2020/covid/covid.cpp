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

double dist(ll2 p1, ll2 p2){
    return std::sqrt(std::pow(p1.fi-p2.fi, 2)+std::pow(p1.se-p2.se, 2));
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

        int N;
        std::cin>>N;
        std::vector<ll2> p(N);
        for(int i=0;i<N;i++) std::cin>>p[i].fi>>p[i].se;
        int Z;
        std::cin>>Z;
        std::vector<ll3> c(Z);
        for(int i=0;i<Z;i++) std::cin>>c[i].se.fi>>c[i].se.se>>c[i].fi;
        ll D;
        std::cin>>D;

        std::vector<ll> score(N, 0);
        int best = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<Z;j++)
                if(dist(p[i], c[j].se) <= D) score[i] += c[j].fi;
            if(score[i] > score[best]) best = i;
        }
        
        std::cout<<best+1<<"\n";
    }
}

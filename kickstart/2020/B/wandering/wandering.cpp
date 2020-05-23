#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define MAXN 100001

double W, H;
ld fact[2*MAXN+1], p2[2*MAXN+1], edge_low[MAXN], edge_right[MAXN];

ld prob(int x, int y){
    if(x < 1 || y < 1)
        return 0;
    if(x == H)
        return edge_low[y];
    if (y == W)
        return edge_right[x];
    return std::exp(fact[x+y-2]-(fact[x-1]+fact[y-1]) - p2[x+y-2]);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    fact[0] = 0;
    p2[0] = 0;
    for(int i=1;i<=2*MAXN;i++){
        fact[i] = fact[i-1] + std::log(i);
        p2[i] = p2[i-1] + std::log(2);
    }

    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++){
        std::cout<<"Case #"<<t<<": ";
        int W, H, L, U, R, D;
        std::cin>>W>>H>>L>>U>>R>>D;

        if((U == 1 && D == H) || (L == 1 && R == W)){
            std::cout<<"0.0\n";
            continue;
        }

        edge_low[0] = 0;
        for(int i=1;i<W;i++)
            edge_low[i] = edge_low[i-1] + prob(H-1, i)/2;
        edge_right[0] = 0;
        for(int i=1;i<H;i++)
            edge_right[i] = edge_right[i] + prob(i, W-1)/2;
        edge_low[W] = edge_right[H] = 1;

        ld res = 1.0;
        if(U > 1)
            for(int i=L;i<=R;i++){
                if(i == W) res -= prob(U-1, i);
                else res -= prob(U-1, i)/2;
            }
        if(L > 1)
            for(int i=U;i<=D;i++){
                if(i == H) res -= prob(i, L-1);
                else res -= prob(i, L-1)/2;
            }

        if(res < 0.0) res = -res;
        if(res < 0.0000001) res = 0.0;

        if(res >= 0.0) printf("%.06LG\n", res);
        else  printf("%.06LG\n", -res);
    }
}

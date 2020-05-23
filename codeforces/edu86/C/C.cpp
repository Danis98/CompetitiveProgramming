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
        ll A, B, Q;
        std::cin>>A>>B>>Q;
        ll per = 0;
        std::vector<ll> pre(A*B, 0);
        for(ll j=0;j<A*B;j++){
            if(j>0) pre[j] = pre[j-1];
            if((j%A)%B != (j%B)%A)
                pre[j]++;
        }
        per = pre[A*B-1];
        for(int i=0;i<Q;i++){
            ll L, R;
            std::cin>>L>>R;
            ll res = per * (R / (A*B) - L / (A*B));
            if(L%(A*B) != 0) res -= pre[(L-1+A*B)%(A*B)];
            res += pre[R%(A*B)];
            std::cout<<res<<" ";
        }
        std::cout<<"\n";
    }
}

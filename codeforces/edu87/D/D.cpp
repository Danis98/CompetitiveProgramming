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

    ll N, Q;
    std::cin>>N>>Q;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    std::vector<ll> k(Q);
    for(int i=0;i<Q;i++) std::cin>>k[i];
    int ctr = N;
    for(int i=0;i<Q;i++)
        if(k[i]<0) ctr--;
        else ctr++;
    if(ctr == 0){
        std::cout<<"0\n";
        return 0;
    }
}

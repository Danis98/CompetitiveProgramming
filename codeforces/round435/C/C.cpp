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

    ll N, X;
    std::cin>>N>>X;
    if(N == 1){
        std::cout<<"YES\n"<<X<<"\n";
        return 0;
    }
    else if(N == 2){
        if(X == 0) std::cout<<"NO\n";
        else std::cout<<"YES\n0 "<<X<<"\n";
        return 0;
    }
    std::vector<ll> a(N);
    a[0] = 1 << 18;
    ll r = a[0];
    for(int i=1;i<N-1;i++){
        a[i] = i;
        r ^= a[i];
    }
    if((r ^ X) == a[0]){
        r ^= a[1];
        a[1] = 0;
    }
    a[N-1] = r ^ X;
    std::cout<<"YES\n";
    for(int i=0;i<N;i++)
        std::cout<<a[i]<<" \n"[i==N-1];
}

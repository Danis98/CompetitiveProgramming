#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll2, ll> ll3;
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

    ll N;
    std::cin>>N;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    std::vector<ll> preO(N, 0), preE(N, 0);
    for(int i=0;i<N;i++){
        if(i>0){
            preO[i] = preO[i-1];
            preE[i] = preE[i-1];
        }
        if(i%2==0) preE[i] += a[i];
        else preO[i] += a[i];
    }
    ll best = preE[N-1];
    for(int i=1;i<N;i++){
        if(i%2==0)
            best = std::max(best, preO[i-1]+preE[N-1]-preE[i-1]);
        else
            best = std::max(best, preE[i-1]+preO[N-1]-preO[i-1]);
    }
    std::cout<<best<<"\n";
}

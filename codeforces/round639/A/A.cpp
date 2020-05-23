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
        std::vector<ll> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        std::vector<ll> res(N, 0);
        for(int i=0;i<N;i++){
            ll idx = i+a[i];
            if(idx < 0){
                idx *= -1;
                idx %= N;
                idx = (N - idx) % N;
            }
            else idx %= N;
            res[idx]++;
        }
        bool valid = true;
        for(int i=0;i<N;i++)
            valid &= res[i] == 1;
        if(valid) std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
}

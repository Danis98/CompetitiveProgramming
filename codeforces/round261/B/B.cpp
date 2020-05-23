#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
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

    int N;
    std::cin>>N;
    ll max = -1, max_n = 0, min = 1000000001, min_n = 0;
    for(int i=0;i<N;i++){
        ll t;
        std::cin>>t;
        if(max < t){
            max = t;
            max_n = 1;
        }
        else if(max == t) max_n++;
        if(min > t){
            min = t;
            min_n = 1;
        }
        else if(min == t) min_n++;
    }
    std::cout<<(max-min)<<" "<<(max == min ? (max_n*(max_n-1))/2 : (max_n * min_n))<<"\n";
}

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

ll2 vec(ll2 a, ll2 b){
    return {b.first - a.first, b.second - b.second};
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N;
    std::vector<ll2> pts;
    std::cin>>N;
    pts.resize(N);
    for(int i=0;i<N;i++) std::cin>>pts[i].first>>pts[i].second;
    if(N%2){
        std::cout<<"NO\n";
        return 0;
    }
    ll2 sum = {pts[0].first+pts[N/2].first, pts[0].second+pts[N/2].second};
    for(int i=1;i<N/2;i++){
        // ll2 vec1 = vec(pts[i], pts[i+1]);
        // ll2 vec2 = vec(pts[N/2+i], pts[(N/2+i+1) % N]);
        // if(!(vec1.first == - vec2.first && vec1.second == -vec2.second)){
        //     std::cout<<"NO\n";
        //     return 0;
        // }
        ll2 s = {pts[i].first+pts[N/2+i].first, pts[i].second+pts[N/2+i].second};
        if(s != sum){
            std::cout<<"NO\n";
            return 0;
        }
    }
    std::cout<<"YES\n";
}

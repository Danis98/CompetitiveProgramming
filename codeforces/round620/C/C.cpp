#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
        ll N, M;
        std::cin>>N>>M;
        ll2 poss_range = {M, M};
        ll curr_t = 0;
        bool poss = true;
        std::vector<std::pair<ll, ll2>> Q(N);
        for(int i=0;i<N;i++){
            std::cin>>Q[i].first>>Q[i].second.first>>Q[i].second.second;
        }
        std::sort(Q.begin(), Q.end());
        for(int i=0;i<N;i++){
            ll t = Q[i].first;
            ll l = Q[i].second.first;
            ll h = Q[i].second.second;
            poss_range.first -= t - curr_t;
            poss_range.second += t - curr_t;
            // std::cout<<poss_range.first<<" "<<poss_range.second<<" "<<l<<" "<<h<<"\n";
            poss_range.first = std::max(poss_range.first, l);
            poss_range.second = std::min(poss_range.second, h);
            if(poss_range.first > poss_range.second){
                poss = false;
                break;
            }
            curr_t = t;
        }
        if(poss) std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
}

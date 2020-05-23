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

    ll N, K;
    std::cin>>N>>K;
    std::string S;
    std::cin>>S;
    std::vector<std::vector<int>> moves;
    ll ctr = 0;
    while(true){
        std::vector<int> cur_m;
        for(int i=0;i<N-1;i++)
            if(S[i] == 'R' && S[i+1] == 'L'){
                S[i] = 'L';
                S[i+1] = 'R';
                cur_m.pb(i);
                i++;
                ctr++;
            }
        if(cur_m.size() == 0) break;
        else moves.pb(cur_m);
    }
    ll extra = K - moves.size();
    if(moves.size() > K || ctr < K){
        std::cout<<"-1\n";
        return 0;
    }
    for(std::vector<int> m : moves){
        int rem = std::max(0LL, (ll)m.size() - extra);
        // std::cout<<"["<<m.size()<<" "<<extra<<" "<<rem<<"]\n";
        for(int i=0;i<(ll)m.size()-rem;i++)
            std::cout<<"1 "<<m[i]+1<<"\n";
        if(rem > 0){
            std::cout<<rem<<" ";
            for(int i=(ll)m.size()-rem;i<m.size();i++)
                std::cout<<m[i]+1<<" ";
            std::cout<<"\n";
        }
        extra -= (ll)m.size() - rem - 1;
    }
}

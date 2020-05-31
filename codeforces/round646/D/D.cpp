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
    int T;
    std::cin>>T;
    while(T--){
        ll N, K;
        std::cin>>N>>K;
        std::vector<std::vector<ll>> S;
        std::vector<bool> used(N+1, false);
        for(int i=0;i<K;i++){
            std::vector<ll> c;
            ll len;
            std::cin>>len;
            c.resize(len);
            for(int j=0;j<len;j++){
                std::cin>>c[j];
                used[c[j]] = true;
            }
            S.pb(c);
        }
        std::vector<ll> left;
        for(int i=1;i<=N;i++) if(!used[i]) left.pb(i);
        S.pb(left);
        ll global_max;
        std::cout<<"? "<<N;
        for(int i=1;i<=N;i++)
            std::cout<<" "<<i;
        std::cout<<std::endl;
        std::cin>>global_max;
        ll a = 0, b = S.size()-1;
        while(a < b){
            ll mid = (a+b)/2;
            std::vector<ll> idx;
            for(int i=a;i<=mid;i++)
                for(ll j : S[i]) idx.pb(j);
            std::cout<<"? "<<idx.size();
            for(ll i : idx) std::cout<<" "<<i;
            std::cout<<std::endl;
            ll res;
            std::cin>>res;
            if(res < global_max) a = mid+1;
            else b = mid;
        }
        ll sec;
        std::vector<ll> idx;
        for(int i=0;i<S.size();i++)
            if(i != a)
                for(ll j : S[i]) idx.pb(j);
        std::cout<<"? "<<idx.size();
        for(ll i : idx) std::cout<<" "<<i;
        std::cout<<std::endl;
        std::cin>>sec;
        std::vector<ll> P(K, global_max);
        if(a < K)
            P[a] = sec;
        std::cout<<"!";
        for(int i=0;i<K;i++)
            std::cout<<" "<<P[i];
        std::cout<<std::endl;
        std::string resp;
        std::cin>>resp;
        if(resp != "Correct") break;
    }
}

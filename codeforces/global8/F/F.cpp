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
    ll N;
    std::cin>>N;
    std::vector<ll> a(N, 0);
    ll R = 0, K = 0;
    for(int k=2;k<=N;k++){
        ll r = 0;
        for(int i=0;i<N-1;i++)
            if(i%k != k-1) r++;
        r -= k-1;
        if(r > R){
            R = r;
            K = k;
        }
    }
    ll cur = 0;
    while(cur < R){
        std::vector<ll> idx;
        for(int i=0;i<N-1;i++)
            if(i%K != K-1 && a[i] == 0){
                idx.pb(i+1);
                a[i] = 1;
                cur++;
                if(idx.size() == K) break;
            }
        std::cout<<K<<" ";
        for(ll i : idx) std::cout<<i<<" ";
        std::cout<<std::endl;
        ll X;
        std::cin>>X;
        X--;
        for(int i=X;i<X+K;i++){
            cur -= a[i%N];
            a[i%N] = 0;
        }
    }
    std::cout<<"0"<<std::endl;
}

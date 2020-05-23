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
        ll N, L, R;
        std::cin>>N>>L>>R;
        L--;
        R--;
        ll start = 0;
        int idx = 1;
        int av = 2;
        int ctr = 0;
        while(start < R){
            idx = 1 + ctr;
            ll len = (N - ctr - 1) * 2;
            ctr++;
            if(start+len-1 >= L){
                // std::cout<<"["<<ctr<<" "<<idx<<" "<<start<<" "<<len<<"]\n";
                for(ll j=0;j<len && start<=R;j++){
                    if(start >= L){
                        if(j % 2 == 0) std::cout<<idx<<" ";
                        else if(j % 2 == 1) std::cout<<(idx+j/2+1)<<" ";
                    }
                    start++;
                }
            }
            else start += len;
        }
        // std::cout<<"{"<<start<<" "<<R<<"}\n";
        if(start == R) std::cout<<"1";
        std::cout<<"\n";
    }
}

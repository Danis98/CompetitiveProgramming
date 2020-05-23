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
        std::vector<ll> c(1, 1);
        ll p = 2;
        while(2*(p>>1)-1 <= N){
            c.pb(p);
            p <<= 1;
        }
        ll sum = 0;
        for(int e : c) sum += e;
        while(sum - N >= c[c.size()-1]){
            sum -= c[c.size()-1];
            c.pop_back();
        }
        
        ll post = 1;
        for(int i=c.size()-1;i>=1;i--){
            if(sum <= N) break;
            ll sub = std::min(post * (c[i]-c[i-1]), sum - N);
            // std::cout<<"["<<i<<" "<<sub<<" "<<sum-N<<"]"<<std::endl;
            for(int j=i;j<c.size();j++) c[j] -= sub/post;
            for(int j=0;j<sub%post;j++) c[i+j]--;
            post++;
            sum -= sub;
        }

        // for(int e : c)
        //     std::cout<<e<<" ";
        // std::cout<<"\n";

        std::cout<<c.size()-1<<"\n";
        for(int i=1;i<c.size();i++)
            std::cout<<c[i]-c[i-1]<<" ";
        std::cout<<"\n";
    }
}

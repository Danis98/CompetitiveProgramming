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

#define MAXV 100

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
        std::vector<ll> freq(MAXV+1, 0);
        for(int i=0;i<N;i++){
            std::cin>>a[i];
            freq[a[i]]++;
        }
        ll e = 0, o = 0;
        for(int i=0;i<N;i++)
            if(a[i]%2) o++;
            else e++;
        if(e%2 == 0 && o%2 == 0)
            std::cout<<"YES\n";
        else if(e%2 == 1 && o%2 == 1){
            bool poss = false;
            for(int i=1;i<MAXV;i++)
                if(freq[i] && freq[i+1]){
                    poss = true;
                    break;
                }
            if(poss) std::cout<<"YES\n";
            else std::cout<<"NO\n";
        }
        else
            std::cout<<"NO\n";
    }
}

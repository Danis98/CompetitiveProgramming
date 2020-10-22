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
        int N;
        std::cin>>N;
        std::vector<int> a(N);
        bool diff = false;
        for(int i=0;i<N;i++){
            std::cin>>a[i];
            if(a[i] != a[0]) diff = true;
        }
        if(!diff){
            std::cout<<"NO\n";
            continue;
        }
        std::cout<<"YES\n";
        int sec = -1;
        for(int i=1;i<N;i++){
            if(a[i] != a[0]){
                std::cout<<"1 "<<(i+1)<<"\n";
                sec = i+1;
            }
        }
        for(int i=1;i<N;i++)
            if(a[i] == a[0])
                std::cout<<sec<<" "<<(i+1)<<"\n";
    }
}

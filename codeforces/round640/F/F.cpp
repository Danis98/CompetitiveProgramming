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
        ll N0, N1, N2;
        std::cin>>N0>>N1>>N2;
        std::string s;
        if(N0 == 0 && N1 == 0){
            s = "1";
            for(int i=0;i<N2;i++)
                s += "1";
        }
        else{
            s = "0";
            for(int i=0;i<N0;i++)
                s += "0";
            if(N1 > 0){
                s += "1";
                N1--;
                for(int i=0;i<N2;i++)
                    s += "1";
                for(int i=0;i<N1;i++)
                    s += "01"[i%2];
            }
        }
        std::cout<<s<<"\n";
    }
}

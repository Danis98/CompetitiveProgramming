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
        ll N, M;
        std::cin>>N>>M;
        std::vector<std::string> s(N);
        for(int i=0;i<N;i++) std::cin>>s[i];
        bool found = false;
        for(int i=0;i<M;i++){
            std::string t = s[0];
            for(char ch='a';ch<='z';ch++){
                t[i] = ch;
                bool valid = true;
                for(int j=0;j<N;j++){
                    ll d = 0;
                    for(int k=0;k<M;k++)
                        d += s[j][k] != t[k];
                    // std::cout<<"["<<s[j]<<"<->"<<t<<"="<<d<<"]\n";
                    if(d > 1){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    found = true;
                    std::cout<<t<<"\n";
                    break;
                }
            }
            if(found) break;
        }
        if(!found) std::cout<<"-1\n";
    }
}

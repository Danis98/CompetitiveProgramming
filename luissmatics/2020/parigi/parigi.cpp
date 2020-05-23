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
    for(int t=1;t<=T;t++){
        int N;
        std::cin>>N;
        std::set<std::string> S;
        std::string str;
        std::getline(std::cin, str);
        for(int i=0;i<N;i++){
            std::getline(std::cin, str);
            S.insert(str.substr(11));
        }
        std::cout<<"Case #"<<t<<": "<<S.size()<<"\n";
    }
}

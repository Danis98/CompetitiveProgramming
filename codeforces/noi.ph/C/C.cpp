#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int T, N;
    std::string S;
    std::cin>>T;
    for(int t=0;t<T;t++){
        std::cin>>N>>S;
        int a = 0, b = 0, c = 0, pos = S.find("TJ");
        while(pos != std::string::npos){
            pos = S.find("TJ", pos+1);
            a++;
        }
        pos = S.find("si");
        while(pos != std::string::npos){
            pos = S.find("si", pos+1);
            b++;
        }
        pos = S.find("log");
        while(pos != std::string::npos){
            pos = S.find("log", pos+1);
            c++;
        }
        std::cout<<a<<" "<<b<<" "<<c<<"\n";
    }
}

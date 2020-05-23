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

    std::string S, hello = "hello";
    std::cin>>S;

    int ctr = 0;
    for(int i=0;i<S.length();i++){
        if(S[i] == hello[ctr]) ctr++;
        if(ctr == hello.length()) break;
    }

    if(ctr == hello.length()) std::cout<<"YES\n";
    else std::cout<<"NO\n";
}

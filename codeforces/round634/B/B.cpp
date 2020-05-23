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
        int N, A, B;
        std::cin>>N>>A>>B;
        std::string S = "";
        std::vector<int> freq(26, 0);
        for(int i=0;i<A;i++)
            S += 'a' + i%B;
        for(int i=A;i<N;i++)
            S += S[i-A];
        std::cout<<S<<"\n";
    }
}

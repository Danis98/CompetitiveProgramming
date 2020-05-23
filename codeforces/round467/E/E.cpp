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

    int N;
    std::string a, b;
    std::cin>>N>>a>>b;
    std::map<char, int> af, bf;
    for(int i=0;i<N;i++) af[a[i]]++;
    for(int i=0;i<N;i++) bf[b[i]]++;

    for(char c='a';c<='z';c++)
        if(af[c] != bf[c]){
            std::cout<<"-1\n";
            return 0;
        }

    std::vector<int> moves;
    
}

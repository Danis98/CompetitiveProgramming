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

    int ctr = 0;
    std::vector<int> freq(26, 0);
    while(true){
        char ch;
        std::cin>>ch;
        if(ch == '}') break;
        if(ctr%2 == 1) freq[ch-'a']++;
        ctr++;
    }
    ctr = 0;
    for(int i=0;i<26;i++) if(freq[i] > 0) ctr++;
    std::cout<<ctr<<"\n";
}

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

    std::string S;
    std::cin>>S;
    std::vector<ll> pre(S.length());
    for(int i=0;i<S.length()-1;i++){
        pre[i] = i == 0 ? 0 : pre[i-1];
        if(S[i] == S[i+1]) pre[i]++;
    }

    int M;
    std::cin>>M;
    for(int i=0;i<M;i++){
        int l, r;
        std::cin>>l>>r;
        l--; r--;
        if(l == 0) std::cout<<pre[r-1]<<"\n";
        else std::cout<<(pre[r-1] - pre[l-1])<<"\n";
    }
}

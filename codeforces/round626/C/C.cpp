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

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::string S;
    std::cin>>N>>S;

    int bad_start = -1, ctr = 0;
    int res = 0;
    for(int i=0;i<N;i++){
        if(S[i] == ')') ctr--;
        else ctr++;
        if(ctr < 0 && bad_start == -1) bad_start = i;
        else if(ctr == 0 && bad_start != -1){
            res += i - bad_start + 1;
            bad_start = -1;
        }
    }
    if(ctr == 0) std::cout<<res<<"\n";
    else std::cout<<"-1\n";
}

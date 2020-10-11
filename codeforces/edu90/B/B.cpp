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
        std::string S;
        std::cin>>S;
        ll moves = 0;
        ll N = S.length();
        for(int i=0;i<N;i++){
            ll prev = -1;
            bool found = false;
            for(int j=0;j<N;j++){
                if(S[j]=='2') continue;
                if(prev != -1 && S[prev] != '2' && S[prev] != S[j]){
                    S[prev] = '2';
                    S[j] = '2';
                    moves++;
                    found = true;
                    break;
                }
                prev = j;
            }
            if(!found) break;
        }
        if(moves%2==0) std::cout<<"NET\n";
        else std::cout<<"DA\n";
    }
}

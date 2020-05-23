#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
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
    S = "0"+S;
    int min_p = 1;

    int ptr = S.length()-1, rep = 0, op = 0;
    while(ptr > min_p){
        if(S[ptr] == '0'){
            op++;
            ptr--;
        }
        else{
            for(int i=ptr;i>=0;i--){
                if(S[i] == '0'){
                    S[i] = '1';
                    min_p = std::min(min_p, i);
                    break;
                }
                S[i] = '0';
            }
            op++;
        }
    }
    std::cout<<op<<"\n";
}

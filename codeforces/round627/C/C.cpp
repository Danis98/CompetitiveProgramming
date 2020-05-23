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

    int T;
    std::cin>>T;
    while(T--){
        std::string S;
        std::cin>>S;
        int N = S.length();
        int a = 1, b = N + 1;
        while(a != b){
            int mid = (a + b) / 2;
            // std::cout<<"d="<<mid<<"\n";
            int reach = mid - 1;
            for(int i=0;i<N && i<=reach;i++){
                if(S[i] == 'R') reach = std::max(reach, i + mid);
                // std::cout<<"["<<reach<<"]\n";
            }
            if(reach >= N) b = mid;
            else a = mid + 1;
        }
        std::cout<<a<<"\n";
    }
}

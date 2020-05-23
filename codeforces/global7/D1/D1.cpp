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
        std::string s;
        std::cin>>s;
        int N = s.length();
        int comm = 0;
        for(;comm<N/2;comm++) if(s[comm] != s[N - comm - 1]) break;
        // std::cout<<comm<<"\n";
        int idx = comm;
        for(int i=comm;i<N-comm;i++){
            bool pal = true;
            for(int j=comm;j<=i;j++){
                if(s[j] != s[comm+i-j]){
                    pal = false;
                    break;
                }
            }
            if(pal)
                idx = std::max(idx, i);
        }
        std::string cand1 = "";
        // std::cout<<idx<<"\n";
        for(int i=0;i<=std::min(idx, N-comm-1);i++) cand1 += s[i];
        for(int i=std::max(idx+1, N-comm);i<N;i++) cand1 += s[i];
        // std::cout<<cand1<<" "<<cand1.length()<<"\n";

        idx = N - comm - 1;
        for(int i=N-comm-1;i>=comm;i--){
            bool pal = true;
            for(int j=N-comm-1;j>=i;j--){
                if(s[j] != s[i+(N-comm-1-j)]){
                    pal = false;
                    break;
                }
            }
            if(pal)
                idx = std::min(idx, i);
        }
        std::string cand2 = "";
        for(int i=0;i<comm;i++) cand2 += s[i];
        for(int i=std::max(idx, comm);i<N;i++) cand2 += s[i];
        // std::cout<<cand2<<" "<<cand2.length()<<"\n";

        if(cand1.length() > cand2.length()) std::cout<<cand1<<"\n";
        else std::cout<<cand2<<"\n";
    }
}

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

std::string get_str(std::string s, int k){
    std::string res = "";
    int N = s.length();
    for(int i=k-1;i<N;i++) res += s[i];
    if((N - k) % 2 == 0)
        for(int i=k-2;i>=0;i--) res += s[i];
    else
        for(int i=0;i<k-1;i++) res += s[i];
    return res;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
        int N;
        std::string S;
        std::cin>>N>>S;
        int best_k = 1;
        std::string best = S;
        for(int k=2;k<=N;k++){
            std::string cand = get_str(S, k);
            if(cand < best){
                best = cand;
                best_k = k;
            }
        }
        std::cout<<best<<"\n"<<best_k<<"\n";
    }
}

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
        int N, L;
        std::string S;
        std::cin>>N>>L>>S;
        int K = N / L;
        std::vector<std::vector<int>> freq(L, std::vector<int>(26, 0));
        for(int i=0;i<N;i++)
            freq[i%L][S[i]-'a']++;
        ll moves = 0;
        for(int i=0;i<L/2;i++){
            int best = -1, best_v = -1;
            for(int j=0;j<26;j++){
                if(freq[i][j]+freq[L-i-1][j]>best_v){
                    best = j;
                    best_v = freq[i][j]+freq[L-i-1][j];
                }
            }
            // std::cout<<"pos: "<<i<<" best: "<<(char)('a'+best)<<" "<<best_v<<"\n";
            moves += 2*K - best_v;
        }
        if(L % 2 == 1){
            int best = -1, best_v = -1;
            for(int j=0;j<26;j++){
                if(freq[L/2][j]>best_v){
                    best = j;
                    best_v = freq[L/2][j];
                }
            }
            moves += K - best_v;
        }

        std::cout<<moves<<"\n";
    }
}

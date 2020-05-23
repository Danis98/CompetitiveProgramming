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

    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
        int N, M;
        std::string S;
        std::cin>>N>>M>>S;
        std::vector<ll> freq(N+1, 0LL);
        for(int i=0;i<M;i++){
            int p;
            std::cin>>p;
            freq[0]++;
            freq[p]--;
        }
        std::vector<int> res(26);
        ll cur_ctr = 1;
        for(int i=0;i<N;i++){
            cur_ctr += freq[i];
            res[S[i]-'a'] += cur_ctr;
        }

        for(int i=0;i<26;i++)
            std::cout<<res[i]<<" ";
        std::cout<<"\n";
    }
}

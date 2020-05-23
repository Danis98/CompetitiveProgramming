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
        ll N, K;
        std::string S;
        std::cin>>N>>K>>S;
        std::sort(S.begin(), S.end());
        std::vector<ll> freq(26, 0);
        for(int i=0;i<N;i++) freq[S[i]-'a']++;

        if(freq[S[0]-'a'] < K){
            std::cout<<S[K-1]<<"\n";
            continue;
        }
        if(freq[S[0]-'a'] == N || freq[S[0]-'a'] == K && freq[S[K]-'a'] == N-K){
            for(int i=(N-1)%K;i<N;i+=K) std::cout<<S[i];
            std::cout<<"\n";
            continue;
        }

        for(int i=K-1;i<N;i++)
            std::cout<<S[i];
        std::cout<<"\n";
    }
}

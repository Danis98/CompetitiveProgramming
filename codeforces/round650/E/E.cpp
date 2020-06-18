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
        std::cin>>N>>K;
        std::string S;
        std::cin>>S;
        if(N<=K){
            for(int i=1;i<K;i++)
                if(K%i==0 && K/i<=N){
                    std::cout<<K/i<<"\n";
                    break;
                }
            continue;
        }
        std::vector<ll> freq(26, 0);
        for(int i=0;i<N;i++) freq[S[i]-'a']++;
        ll res = K;
        std::sort(freq.begin(), freq.end());
        std::reverse(freq.begin(), freq.end());
        for(int p=1;p<=K;p++){
            if(K%p != 0) continue;
            ll a=1, b=N/p;
            for(int i=0;i<26;i++){
                rem -= freq[i]/per;
                best = std::min(best, freq[i]);
                if(rem < 0) break;
            }
            if(rem <= 0) a=mid;
            else b = mid-1;
        }
        std::cout<<a*K<<"\n";
    }
}

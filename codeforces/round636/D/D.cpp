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
        std::vector<ll> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        std::vector<ll> best(2*K+1, 0);
        best[2] = N;

        for(int i=0;i<N/2;i++){
            best[std::min(a[i], a[N-i-1])+1]--;
            if(std::max(a[i], a[N-i-1]) < K)
                best[std::max(a[i], a[N-i-1])+K+1]++;
            best[a[i]+a[N-i-1]]--;
            if(a[i]+a[N-i-1] < 2*K)
                best[a[i]+a[N-i-1]+1]++;
        }

        ll ctr = 0;
        ll res = N;
        for(int i=2;i<=2*K;i++){
            ctr += best[i];
            // std::cout<<ctr<<" \n"[i==2*K];
            res = std::min(res, ctr);
        }

        std::cout<<res<<"\n";

        // std::map<ll, int> freq;
        // for(int i=0;i<N/2;i++)
        //     freq[a[i]+a[N-i-1]]++;
        // ll best = 0;
        // for(auto entry : freq)
        //     if(entry.se >= freq[best])
        //         best = entry.fi;
        // int res = 0;
        // for(int i=0;i<N/2;i++){
        //     if(a[i] + a[N-i-1] == best) continue;
        //     else if(best - a[i] >= 1 && best - a[i] <= K)
        //         res++;
        //     else if(best - a[N-i-1] >= 1 && best - a[N-i-1] <= K)
        //         res++;
        //     else res += 2;
        // }
        // std::cout<<res<<"\n";
    }
}

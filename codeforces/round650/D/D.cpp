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
        int N = S.length();
        std::vector<ll> freq(26, 0);
        for(int i=0;i<N;i++)
            freq[S[i]-'a']++;
        int M;
        std::cin>>M;
        std::vector<ll> t(M);
        for(int i=0;i<M;i++) std::cin>>t[i];
        std::vector<ll> idx(M, -1);
        for(int k=0;k<26;k++){
            for(int i=0;i<M;i++){
                if(idx[i] != -1) continue;
                ll ctr = 0;
                for(int j=0;j<M;j++)
                    if(idx[j] != -1 && idx[j] != k)
                        ctr += std::abs(i-j);
                if(ctr == t[i])
                    idx[i] = k;
            }
        }
        // for(int i=0;i<M;i++)
        //     std::cout<<idx[i]<<" \n"[i==M-1];
        std::vector<ll> f2(26, 0);
        for(int i=0;i<M;i++) f2[idx[i]]++;
        int p = 25;
        std::vector<ll> idx2char(26, -1);
        for(int i=0;i<26;i++){
            if(f2[i]==0) continue;
            while(p >= 0 && freq[p] < f2[i]) p--;
            idx2char[i] = p;
            p--;
        }
        for(int i=0;i<M;i++)
            std::cout<<(char)('a'+idx2char[idx[i]]);
        std::cout<<"\n";
    }
}

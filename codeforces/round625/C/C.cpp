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

    int N;
    std::string S;
    std::cin>>N>>S;

    std::map<char, std::vector<int>> ch_pos;
    std::vector<int> prev(N), next(N), vis(N, 0);

    for(int i=0;i<N;i++){
        prev[i] = i - 1;
        next[i] = i + 1;
        ch_pos[S[i]].push_back(i);
    }
    next[N-1] = -1;
    int res = 0;
    for(char ch='z';ch>='a';ch--){
        std::queue<int> Q;
        for(int p : ch_pos[ch])
            if(next[p] != -1 && S[next[p]] == S[p]-1 || prev[p] != -1 && S[prev[p]] == S[p]-1){
                vis[p] = 1;
                Q.push(p);
            }
        while(!Q.empty()){
            int n = Q.front();
            Q.pop();
            res++;
            // std::cout<<"CANCELLING "<<S[n]<<" AT "<<n<<"\n";
            if(prev[n] != -1){
                next[prev[n]] = next[n];
                if(S[prev[n]] == S[n] && !vis[prev[n]]){ vis[prev[n]] = 1; Q.push(prev[n]);}
            }
            if(next[n] != -1){
                prev[next[n]] = prev[n];
                if(S[next[n]] == S[n] && !vis[next[n]]){ vis[next[n]] = 1; Q.push(next[n]);}
            }
        }
    }
    std::cout<<res<<"\n";
}

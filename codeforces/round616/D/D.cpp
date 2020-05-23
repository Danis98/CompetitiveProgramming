#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int freq[200005][26];
int prev[200005][26];
int next[200005][26];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::string S;
    int Q;
    std::cin>>S;
    int N = S.length();
    for(int i=0;i<N;i++){
        if(i>0) for(int j=0;j<26;j++){
            freq[i][j] = freq[i-1][j];
            prev[i][j] = prev[i-1][j];
        }
        if(i == 0) for(int j=0;j<26;j++) prev[i][j] = -1;
        freq[i][S[i]-'a']++;
        prev[i][S[i]-'a'] = i;
    }
    for(int i=0;i<26;i++) next[N-1][i] = -1;
    next[N-1][S[N-1]-'a'] = N-1;
    for(int i=N-2;i>=0;i--){
        for(int j=0;j<26;j++) next[i][j] = next[i+1][j];
        next[i][S[i]-'a'] = i;
    }
    std::cin>>Q;
    for(int i=0;i<Q;i++){
        int l, r;
        std::cin>>l>>r;
        l--;
        r--;
        if(l == r){
            std::cout<<"Yes\n";
            continue;
        }
        bool found=false;
        for(int x=0;x<26;x++){
            if(found) break;
            for(int y=0;y<26;y++){
                if(x == y || x == S[l]-'a' || y == S[r]-'a') continue;
                int last_x = prev[r][x], first_y = next[l][y];
                if(last_x == -1 || first_y == -1) continue;
                if(last_x > first_y) {
                    found = true;
                    break;
                }
            }
        }
        if(found) std::cout<<"Yes\n";
        else std::cout<<"No\n";
    }
}

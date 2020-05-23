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
    std::cin>>S;
    N = S.length();

    ll freq[26][N];
    for(int i=0;i<26;i++) freq[i][0] = 0;
    freq[S[0]-'a'][0] = 1;
    for(int i=1;i<N;i++){
        for(int j=0;j<26;j++) freq[j][i] = freq[j][i-1];
        freq[S[i]-'a'][i]++;
    }
    ll res = 1;
    for(int i=0;i<26;i++) res = std::max(res, freq[i][N-1]);
    ll couples[26][26];
    for(int i=0;i<26;i++) for(int j=0;j<26;j++) couples[i][j] = 0;
    for(int i=1;i<N;i++)
        for(int j=0;j<26;j++)
            couples[j][S[i]-'a'] += freq[j][i-1];

    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            // std::cout<<couples[i][j]<<" ";
            res = std::max(res, couples[i][j]);
        }
        // std::cout<<"\n";
    }
    std::cout<<res<<"\n";
}

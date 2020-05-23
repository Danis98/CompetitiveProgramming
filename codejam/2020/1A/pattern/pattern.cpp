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
    for(int t=1;t<=T;t++){
        std::cout<<"Case #"<<t<<": ";

        int N;
        std::cin>>N;
        std::vector<std::string> s(N);
        std::vector<int> beg(N), end(N);
        for(int i=0;i<N;i++) std::cin>>s[i];

        std::string pre = "", suf = "";
        bool valid = true;
        for(int i=0;i<N;i++){
            for(int j=0;j<s[i].length();j++){
                if(s[i][j] == '*'){
                    beg[i] = j;
                    break;
                }
                if(j < pre.length() && s[i][j] != pre[j]){
                    valid = false;
                    break;
                }
                else if(j >= pre.length()) pre += s[i][j];
            }
            for(int j=0;j<s[i].length();j++){
                if(s[i][s[i].length()-j-1] == '*'){
                    end[i] = s[i].length()-j-1;
                    break;
                }
                if(j < suf.length() && s[i][s[i].length()-j-1] != suf[suf.length()-j-1]){
                    valid = false;
                    break;
                }
                else if(j >= suf.length()) suf = s[i][s[i].length()-j-1] + suf;
            }
            if(!valid) break;
        }
        if(!valid) std::cout<<"*\n";
        else{
            std::cout<<pre;
            for(int i=0;i<N;i++)
                for(int j=beg[i];j<end[i];j++)
                    if(s[i][j] != '*') std::cout<<s[i][j];
            std::cout<<suf<<"\n";
        }
    }
}

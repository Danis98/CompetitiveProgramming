#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

std::string rev(std::string str){
    int M = str.length();
    std::string r = str;
    for(int i=0;i<M;i++) r[M-i-1] = str[i];
    return r;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N, M;
    std::cin>>N>>M;
    std::vector<int> opp(N);
    std::vector<std::string> S(N);
    std::map<std::string, bool> pal;
    for(int i=0;i<N;i++){ std::cin>>S[i]; opp[i] = -1;}

    std::map<std::string, int> freq;
    for(int i=0;i<N;i++) freq[S[i]]++;

    for(int i=0;i<N;i++){
        pal[S[i]] = true;
        for(int j=0;j<=M/2;j++){
            if(S[i][j] != S[i][M-j-1]){
                pal[S[i]] = false;
                break;
            }
        }
    }

    std::string c = "";
    int mlen = 0;
    std::string h = "";
    for(auto entry : freq){
        int matches = std::min(entry.second, freq[rev(entry.first)]) / (pal[entry.first]?2:1);
        mlen += matches;
        entry.second -= matches;
        freq[rev(entry.first)] -= matches;
        for(int i=0;i<matches;i++){
            h += entry.first;
        }
    }

    for(auto center : freq){
        if(!pal[center.first]) continue;
        if(center.second % 2 == 1) c = center.first;
    }

    std::cout<<(h.length()*2+c.length())<<"\n";
    std::cout<<h<<c<<rev(h)<<"\n";
}

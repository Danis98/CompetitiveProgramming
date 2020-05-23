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

    int N, K;
    std::cin>>N>>K;
    std::vector<std::string> words(N);
    for(int i=0;i<N;i++) std::cin>>words[i];
    int line_len = 0, line_start = 0;
    for(int i=0;i<N;i++){
        int new_len = line_len;
        if(line_len == 0) new_len += words[i].length();
        else new_len += 1 + words[i].length();
        if(new_len > K){
            std::cout<<words[line_start];
            for(int j=line_start+1;j<i;j++)
                std::cout<<" "<<words[j];
            std::cout<<"\n";
            line_start = i;
            line_len = words[i].length();
        }
        else line_len = new_len;
    }
    std::cout<<words[line_start];
    for(int j=line_start+1;j<N;j++)
        std::cout<<" "<<words[j];
    std::cout<<"\n";
}

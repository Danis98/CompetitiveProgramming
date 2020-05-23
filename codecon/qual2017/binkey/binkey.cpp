#include <bits/stdc++.h>

int N;
std::string S;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>S;
    int cnt=0;
    for(int i=0;i<N-2;i++){
        if(S[i]=='0' && S[i+1]=='1' && S[i+2]=='0'){
            cnt++;
            S[i+2]='1';
        }
    }

    std::cout<<cnt<<"\n";
}

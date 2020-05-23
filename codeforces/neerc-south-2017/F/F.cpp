#include <bits/stdc++.h>

int N;
std::map<std::string, bool> names;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    std::string S, E;
    int cnt=0;
    for(int i=0;i<N;i++){
        std::cin>>S;
        E="";
        for(int j=S.size()-1;j>=0;j--){
            if(S[j]=='u')
                E+="oo";
            else if(E[E.size()-1]=='h' && S[j]=='k')
                continue;
            else
                E+=S[j];
        }
        if(!names[E]){
            names[E]=true;
            cnt++;
        }
    }
    std::cout<<cnt<<"\n";
}

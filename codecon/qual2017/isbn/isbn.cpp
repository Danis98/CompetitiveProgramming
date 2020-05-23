#include <bits/stdc++.h>

int N;
std::string S;

void check(){
    int checks=0;
    for(int i=0;i<13;i++)
        checks+=(i%2==0?1:3)*(S[i]-'0');
    if(checks%10==0) std::cout<<"VALID\n";
    else std::cout<<"NOT VALID\n";
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    for(int i=0;i<N;i++){
        std::cin>>S;
        check();
    }
}

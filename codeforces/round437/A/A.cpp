#include<bits/stdc++.h>

int N;
std::string S;

int main(){
    std::cin>>N>>S;
    int a=0, b=0;
    for(int i=0;i<N-1;i++)
        if(S[i]=='S' && S[i+1]=='F')
            a++;
        else if(S[i]=='F' && S[i+1]=='S')
            b++;
    if(a>b) std::cout<<"YES\n";
    else std::cout<<"NO\n";
}

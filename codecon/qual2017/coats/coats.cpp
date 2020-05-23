#include <bits/stdc++.h>

int N, M;
int coat[100][100], type[100][100];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M;
    char ch;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            std::cin>>ch;
            if(ch>='A'&&ch<='Z') type[i][j]=0;
            else type[i][j]=1;
            coat[i][j]=ch;
        }
    }

    bool flag=true;
    for(int i=0;i<N && flag;i++)
        for(int j=0;j<M-1 && flag;j++)
            if(type[i][j]==type[i][j+1] && coat[i][j]!=coat[i][j+1])
                flag=false;
    for(int i=0;i<M && flag;i++)
        for(int j=0;j<N-1 && flag;j++)
            if(type[j][i]==type[j+1][i] && coat[j][i]!=coat[j+1][i])
                flag=false;

    if(flag) std::cout<<"VALID\n";
    else std::cout<<"INVALID\n";
}

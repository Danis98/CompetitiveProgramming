#include <bits/stdc++.h>

int N, K, NK;
char model[10][10];
char grid[17000][17000];

void render(int r, int c, int mult){
    if(mult==1){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                grid[r+i][c+j]=model[i][j];
        return;
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(model[i][j]=='.') render(r+i*mult, c+j*mult, mult/N);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    std::cin>>N>>K;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            std::cin>>model[i][j];
    NK=N;
    int kk=K-1;
    while(kk){
        NK*=N;
        kk--;
    }
    render(0, 0, NK/N);
    char S[NK+1];
    for(int i=0;i<NK;i++){
        int ind=0;
        for(int j=0;j<NK;j++)
            if(grid[i][j]=='.') S[ind++]='.';
            else S[ind++]='*';
        S[ind]=0;
        printf("%s\n", S);
    }
}

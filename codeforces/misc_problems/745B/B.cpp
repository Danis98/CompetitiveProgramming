#include <bits/stdc++.h>

int N, M;
bool grid[500][500];

int X1, X2, Y1, Y2;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M;
    bool flag=false;
    int lastx, lasty;
    for(int i=0;i<N;i++){
        char ch;
        for(int j=0;j<M;j++){
            std::cin>>ch;
            if(ch=='.') grid[i][j]=false;
            if(ch=='X'){
                grid[i][j]=true;
                if(!flag){
                    flag=true;
                    X1=i;
                    Y1=j;
                }
                lastx=i;
                lasty=j;
            }
        }
    }

    X2=lastx;
    Y2=lasty;

    if(X1>X2 || Y1>Y2){
        std::cout<<"NO\n";
        return 0;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(grid[i][j] && (i<X1 || i>X2 || j<Y1 || j>Y2)
            || !grid[i][j] && (i>=X1 && i<=X2 && j>=Y1 && j<=Y2)){
                std::cout<<"NO\n";
                return 0;
            }
        }
    }
    std::cout<<"YES\n";
}

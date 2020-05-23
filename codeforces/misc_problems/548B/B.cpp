#include <bits/stdc++.h>

int N, M, Q;
int grid[500][500];
int row_score[500];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M>>Q;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            std::cin>>grid[i][j];

    //Preprocess
    for(int i=0;i<N;i++){
        int cnt=0;
        row_score[i]=0;
        for(int j=M-1;j>=0;j--){
            if(grid[i][j]==1) cnt++;
            else cnt=0;
            row_score[i]=std::max(row_score[i], cnt);
        }
    }

    //Execute queries
    int r, c;
    for(int i=0;i<Q;i++){
        std::cin>>r>>c;
        r--;
        c--;
        grid[r][c]=(grid[r][c]+1)%2;
        int cnt=0;
        row_score[r]=0;
        for(int j=0;j<M;j++){
            if(grid[r][j]==1) cnt++;
            else cnt=0;
            row_score[r]=std::max(row_score[r], cnt);
        }
        int res=0;
        for(int j=0;j<N;j++) res=std::max(res, row_score[j]);
        std::cout<<res<<"\n";
    }
}

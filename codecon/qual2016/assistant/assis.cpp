#include <bits/stdc++.h>

typedef long long int ll;
typedef std::pair<int, int> ii;

int grid[50][50];
int dp[50][50];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            grid[i][j]=false;
            dp[i][j]=0;
        }
    }

    int N;
    std::cin>>N;
    int x, y;
    for(int i=0;i<N;i++){
        std::cin>>x>>y;
        grid[x][y]=true;
    }

    dp[0][0]=grid[0][0];
    for(int i=1;i<50;i++){
        dp[0][i]=dp[0][i-1]+grid[0][i];
        dp[i][0]=dp[i-1][0]+grid[i][0];
    }

    for(int i=1;i<50;i++)
        for(int j=1;j<50;j++)
            dp[i][j]=std::max(dp[i-1][j], dp[i][j-1])+grid[i][j];

    std::cout<<dp[49][49]<<"\n";
}

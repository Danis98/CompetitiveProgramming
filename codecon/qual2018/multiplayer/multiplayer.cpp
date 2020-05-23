//Problem        : Tracing Vile Angus
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 100

int N;
int grid[MAXN][MAXN];

int dp[MAXN][MAXN][MAXN];

int row_sum(int r, int c1, int c2){
    int cnt=0;
    for(int i=c1;i<=c2;i++) cnt+=grid[r][i];
    return cnt;
}

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>grid[i][j];

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++) dp[i][j][k]=0;

    for(int i=0;i<N;i++) for(int j=0;j<N;j++) dp[0][i][j] = row_sum(0, 0, max(i, j));

    for(int i=1;i<N;i++)
        for(int l=0;l<N;l++)
            for(int r=l;r<N;r++){
                for(int lp=0;lp<l;lp++){
                    for(int rp=lp;rp<r;rp++){
                        dp[i][l][r]=max(dp[i][l][r], dp[i-1][lp][rp]+row_sum(i-1, lp, l)+row_sum(i, rp, r));
                        dp[i][l][r]=max(dp[i][l][r], dp[i-1][lp][rp]+row_sum(i-1, rp, r)+row_sum(i, lp, l));
                        dp[i][l][r]=max(dp[i][l][r], dp[i-1][lp][rp]+row_sum(i-1, lp, r));
                        dp[i][l][r]=max(dp[i][l][r], dp[i-1][lp][rp]+row_sum(i, lp, r));
                    }
                }
            }

    cout<<dp[N-1][N-1][N-1]<<"\n";


    return 0;
}

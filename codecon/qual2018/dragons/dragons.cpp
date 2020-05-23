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

int N, C;
vector<int> x;

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    cin>>N>>C;
    for(int i=0;i<N;i++){
        int p;
        cin>>p;
        x.push_back(p);
    }
    sort(x.begin(), x.end());


    int dp[N][C+1];
    for(int i=0;i<N;i++)
        for(int j=0;j<=C;j++)
            dp[i][j] = 1000000001;

    int res = 0;
    for(int c=2;c<=C;c++){
        for(int i=c-1;i<N;i++){
            dp[i][c] = 0;
            for(int k=c-2;k<i;k++)
                dp[i][c] = max(dp[i][c], min(x[i]-x[k], dp[k][c-1]));
            if(c==C) res = max(res, dp[i][c]);
        }
    }

    /*for(int i=0;i<=C;i++){
        for(int j=0;j<N;j++){
            if(dp[j][i]==1000000001) cout<<"-  ";
            else cout<<dp[j][i]<<" ";
        }
        cout<<"\n";
    }*/

    cout<<res<<"\n";

    //dp[i][c] = max(min(dp[j<i][c-1], x[i]-x[i-1]))

    return 0;
}

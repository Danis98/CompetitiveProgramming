#include <iostream>

#define MAXN 101

int N, B;
int G[MAXN];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>B;
    int S=0;
    for(int i=0;i<N;i++){
        std::cin>>G[i];
        S+=G[i];
    }

    bool dp[N][S+1];
    for(int i=0;i<N;i++) for(int j=0;j<=S;j++) dp[i][j]=false;

    dp[0][G[0]] = true;
    dp[0][0]=true;
    for(int i=1;i<N;i++){
        for(int j=0;j<=S;j++){
            if(dp[i-1][j]){
                dp[i][j]=true;
                dp[i][j+G[i]]=true;
            }
        }
    }
    if(S>B){
        for(int i=B;i<=S;i++){
            for(int j=0;j<N;j++){
                if(dp[j][i]){
                    std::cout<<i<<"\n";
                    return 0;
                }
            }
        }
        for(int i=B-1;i>=0;i--){
            for(int j=0;j<N;j++){
                if(dp[j][i]){
                    std::cout<<i<<"\n";
                    return 0;
                }
            }
        }
    }
    else{
        std::cout<<S<<"\n";
        return 0;
    }
}

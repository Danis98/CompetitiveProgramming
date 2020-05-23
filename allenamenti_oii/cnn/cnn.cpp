#include <bits/stdc++.h>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;

#define INFTY (1<<30)

int N, M;
ii *evt;

std::map<iii, int> dp;
std::map<iii, ii> par;

int main(){
    fin>>N>>M;
    evt=new ii[N];
    for(int i=0;i<N;i++){
        fin>>evt[i].first>>evt[i].second;
        evt[i].first--;
        evt[i].second--;
    }
    dp[{0, {evt[0].first, 0}}]=evt[0].first;
    dp[{0, {0, evt[0].second}}]=evt[0].second;
    for(int i=1;i<N;i++){
        for(int k=0;k<M;k++)
            for(int j=0;j<M;j++){
                //move r
                if(dp[{i, {evt[i].first, j}}]>dp[{i-1, {k, j}}]+abs(k-evt[i].first)
                || dp.find({i, {evt[i].first, j}})==dp.end()){
                    dp[{i, {evt[i].first, j}}]=dp[{i-1, {k, j}}]+abs(k-evt[i].first);
                    par[{i, {evt[i].first, j}}]={k, j};
                }
                //move c
                if(dp[{i, {j, evt[i].second}}]>dp[{i-1, {j, k}}]+abs(k-evt[i].second)
                || dp.find({i, {j, evt[i].second}})==dp.end()){
                    dp[{i, {j, evt[i].second}}]=dp[{i-1, {j, k}}]+abs(k-evt[i].second);
                    par[{i, {j, evt[i].second}}]={j, k};
                }
            }
    }
    ii sol={0, 0};
    for(int i=0;i<M;i++){
        ii minv={evt[N-1].first, i};
        if(dp[{N-1, minv}]>dp[{N-1, {i, evt[N-1].second}}])
            minv={i, evt[N-1].second};
        if(dp[{N-1, sol}]>dp[{N-1, minv}])
            sol=minv;
    }
    std::string str="";
    for(int i=N-1;i>=0;i--){
        if(sol.first==evt[i].first) str+='R';
        else str+='C';
        sol=par[{i, sol}];
    }
    for(int i=N-1;i>=0;i--) fout<<str[i]<<"\n";
/*
    for(int i=0;i<N;i++){+
        printf("%d %d\n", evt[i].first, evt[i].second);
        for(int j=0;j<M;j++){
            for(int k=0;k<M;k++)
                if(dp[{i, {k, j}}]==0)
                    printf("XX       ");
                else
                    printf("%2d (%1d %1d) ", dp[{i, {k, j}}], par[{i, {k, j}}].first, par[{i, {k, j}}].second);
            printf("\n");
        }
        printf("\n");
    }*/
}

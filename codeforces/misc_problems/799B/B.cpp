#include <bits/stdc++.h>

typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;

int N, M;
iii shirt[200000];
int next[3][200000];
bool taken[200000];
int cur[3]={-1, -1, -1};

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    for(int i=0;i<N;i++)
        std::cin>>shirt[i].first;
    for(int i=0;i<N;i++){
        std::cin>>shirt[i].second.first;
        shirt[i].second.first--;
    }
    for(int i=0;i<N;i++){
        std::cin>>shirt[i].second.second;
        shirt[i].second.second--;
    }
    std::sort(shirt, shirt+N);
    for(int i=0;i<N;i++) taken[i]=false;
    for(int i=0;i<N;i++){
        next[0][i]=-1;
        next[1][i]=-1;
        next[2][i]=-1;
    }
    int c0=-1, c1=-1, c2=-1;
    for(int i=0;i<N;i++){
        if(shirt[i].second.first==0 || shirt[i].second.second==0){
            if(c0==-1) cur[0]=i;
            else next[0][c0]=i;
            c0=i;
        }
        if(shirt[i].second.first==1 || shirt[i].second.second==1){
            if(c1==-1) cur[1]=i;
            else next[1][c1]=i;
            c1=i;
        }
        if(shirt[i].second.first==2 || shirt[i].second.second==2){
            if(c2==-1) cur[2]=i;
            else next[2][c2]=i;
            c2=i;
        }
    }

    std::cin>>M;
    for(int i=0;i<M;i++){
        int col;
        std::cin>>col;
        col--;
        while(taken[cur[col]] && cur[col]!=-1)
            cur[col]=next[col][cur[col]];
        if(cur[col]==-1){
            std::cout<<"-1 ";
            continue;
        }
        taken[cur[col]]=true;
        std::cout<<shirt[cur[col]].first<<" ";
    }
    std::cout<<"\n";
}

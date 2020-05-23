#include <bits/stdc++.h>

int R, C;
int initC;
char grid[300][300];
std::set<int> vis[300][300];

int len=0, bestl=0;
char cur[300+1];
char best[300+1];

int hash(){
    int P1=107;
    int P2=1000000007;
    unsigned long long int h=0;
    for(int i=0;i<len;i++)
        h=(h*P1+cur[i])%P2;
    return (int)h;
}

bool valid(){
    int cnt=0;
    for(int i=0;i<len;i++){
        if(cur[i]=='(') cnt++;
        else cnt--;
        if(cnt<0)return false;
    }
    return cnt==0;
}

void move(int r, int c){
    if(c<0 || c>C-1) return;
    if(grid[r][c]=='*' || r<0){
        if(valid() && bestl<=len && (bestl!=len || strcmp(cur,best)<0)){
            strcpy(best, cur);
            bestl=len;
        }
        return;
    }
    if(vis[r][c].find(hash())!=vis[r][c].end()) return;
    vis[r][c].insert(hash());
    if(grid[r][c]=='(' || grid[r][c]==')')
        cur[len++]=grid[r][c];
    move(r-1, c-1);
    move(r-1, c);
    move(r-1, c+1);
    if(grid[r][c]=='(' || grid[r][c]==')')
        cur[(len--)-1]=0;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>R>>C;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            std::cin>>grid[i][j];

    for(int i=0;i<C;i++)
        if(grid[R-1][i]=='M')
            initC=i;

    move(R-1, initC);

    std::cout<<bestl<<"\n"<<best<<"\n";
}

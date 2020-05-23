#include <bits/stdc++.h>

#define PAIR(X, Y) std::make_pair(X, Y)

typedef long long int ll;
typedef std::pair<int, int> ii;

int R, C;
int grid[40][40];
int R1, C1, R2, C2;
int col;
int res;

bool dfs(ii pos, ii par, int d){
    if(pos.first<0 || pos.first>R-1 || pos.second<0 || pos.second>C-1)
        return false;
    if(grid[pos.first][pos.second]!=col) return false;
    if(pos.first==R2 && pos.second==C2){
        res=d;
        return true;
    }
    if(pos.first!=0
    && grid[pos.first-1][pos.second]==col
    && PAIR(pos.first-1, pos.second)!=par)
        if(dfs({pos.first-1, pos.second}, pos, d+1)) return true;
    if(pos.second!=0
    && grid[pos.first][pos.second-1]==col
    && PAIR(pos.first, pos.second-1)!=par)
        if(dfs({pos.first, pos.second-1}, pos, d+1)) return true;
    if(pos.first!=R-1
    && grid[pos.first+1][pos.second]==col
    && PAIR(pos.first+1, pos.second)!=par)
        if(dfs({pos.first+1, pos.second}, pos, d+1)) return true;
    if(pos.second!=C-1
    && grid[pos.first][pos.second+1]==col
    && PAIR(pos.first, pos.second+1)!=par)
        if(dfs({pos.first, pos.second+1}, pos, d+1)) return true;
    return false;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>R>>C;
    char ch;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++){
            std::cin>>ch;
            grid[i][j]=ch-'0';
        }

    std::cin>>R1>>C1>>R2>>C2;
    col=grid[R1][C1];
    dfs({R1, C1}, {-1, -1}, 1);

    std::cout<<res<<"\n";
}

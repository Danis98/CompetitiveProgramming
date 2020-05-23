#include <bits/stdc++.h>

#define SPACE   '.'
#define BKING   'k'
#define BQUEEN  'q'
#define BBISH   'b'
#define BKNIGHT 'n'
#define BROOK   'r'
#define WKING   'K'
#define WQUEEN  'Q'
#define WBISH   'B'
#define WKNIGHT 'N'
#define WROOK   'R'

#define KING 0
#define QUEEN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4

#define INFTY 1000000000

typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;

int N, M;
char board[100][100];
int dist[100][100];
int col[100][100];
ii kwhite, kblack;

iii min_sol;

ii rook(ii start, ii end, int color){
    std::queue<ii> Q;
    Q.push(start);
    dist[start.first][start.second]=0;
    while(!Q.empty()){
        ii coord=Q.front();
        Q.pop();
        int d=dist[coord.first][coord.second];
        int beg=0, end=N-1;
        for(int i=0;i<coord.first;i++) if(col[i][coord.second]+color==0) beg=i;
        for(int i=N-1;i>coord.first;i--) if(col[i][coord.second]+color==0) end=i;
        for(int i=beg;i<=end;i++){
            if(dist[i][coord.second]>d+1){
                dist[i][coord.second]=d+1;
                Q.push({i, coord.second});
            }
        }
        beg=0, end=M-1;
        for(int i=0;i<coord.second;i++) if(col[coord.first][i]+color==0) beg=i;
        for(int i=N-1;i>coord.second;i--) if(col[coord.first][i]+color==0) end=i;
        for(int i=beg;i<=end;i++){
            if(dist[coord.first][i]>d+1){
                dist[coord.first][i]=d+1;
                Q.push({coord.first, i});
            }
        }
    }
    return {ROOK, dist[end.first][end.second]};
}

ii bishop(ii start, ii end, int color){
    std::queue<ii> Q;
    Q.push(start);
    dist[start.first][start.second]=0;
    while(!Q.empty()){
        ii coord=Q.front();
        Q.pop();
        int d=dist[coord.first][coord.second];
        for(int i=0;i<N;i++){
            if(coord.second+(i-coord.first)<0 || coord.second+(i-coord.first)>=N) continue;
            if(dist[i][coord.second+(i-coord.first)]>d+1){
                dist[i][coord.second+(i-coord.first)]=d+1;
                Q.push({i, coord.second+(i-coord.first)});
            }
        }
        for(int i=0;i<N;i++){
            if(coord.second-(i-coord.first)<0 || coord.second-(i-coord.first)>=N) continue;
            if(dist[i][coord.second-(i-coord.first)]>d+1){
                dist[i][coord.second-(i-coord.first)]=d+1;
                Q.push({i, coord.second-(i-coord.first)});
            }
        }
    }
    return {BISHOP, dist[end.first][end.second]};
}

ii queen(ii start, ii end, int color){
    std::queue<ii> Q;
    Q.push(start);
    dist[start.first][start.second]=0;
    while(!Q.empty()){
        ii coord=Q.front();
        Q.pop();
        int d=dist[coord.first][coord.second];
        for(int i=0;i<N;i++){
            if(dist[i][coord.second]>d+1){
                std::cout<<(d+1)<<"\n";
                dist[i][coord.second]=d+1;
                Q.push({i, coord.second});
            }
        }
        for(int i=0;i<M;i++){
            if(dist[coord.first][i]>d+1){
                dist[coord.first][i]=d+1;
                Q.push({coord.first, i});
            }
        }
        for(int i=0;i<N;i++){
            if(coord.second+(i-coord.first)<0 || coord.second+(i-coord.first)>=N) continue;
            if(dist[i][coord.second+(i-coord.first)]>d+1){
                dist[i][coord.second+(i-coord.first)]=d+1;
                Q.push({i, coord.second+(i-coord.first)});
            }
        }
        for(int i=0;i<N;i++){
            if(coord.second-(i-coord.first)<0 || coord.second-(i-coord.first)>=N) continue;
            if(dist[i][coord.second-(i-coord.first)]>d+1){
                dist[i][coord.second-(i-coord.first)]=d+1;
                Q.push({i, coord.second-(i-coord.first)});
            }
        }
    }
    return {QUEEN, dist[end.first][end.second]};
}

ii king(ii start, ii end, int color){
    std::queue<ii> Q;
    Q.push(start);
    dist[start.first][start.second]=0;
    while(!Q.empty()){
        ii coord=Q.front();
        Q.pop();
        int x=coord.first, y=coord.second;
        int d=dist[x][y];
        if(x>0 && y>0 && dist[x-1][y-1]>d+1){
            if(col[x-1][y-1]!=color){
                dist[x-1][y-1]=d+1;
                Q.push({x-1, y-1});
            }
        }
        if(y>0 && dist[x][y-1]>d+1){
            dist[x][y-1]=d+1;
            Q.push({x, y-1});
        }
        if(x<N-1 && y>0 && dist[x+1][y-1]>d+1){
            dist[x+1][y-1]=d+1;
            Q.push({x+1, y-1});
        }
        if(x>0 && dist[x-1][y]>d+1){
            dist[x-1][y]=d+1;
            Q.push({x-1, y});
        }
        if(x<N-1 && dist[x+1][y]>d+1){
            dist[x+1][y]=d+1;
            Q.push({x+1, y});
        }
        if(x>0 && y<M-1 && dist[x-1][y+1]>d+1){
            dist[x-1][y+1]=d+1;
            Q.push({x-1, y+1});
        }
        if(y<M-1 && dist[x][y+1]>d+1){
            dist[x][y+1]=d+1;
            Q.push({x, y+1});
        }
        if(x<N-1 && y<M-1 && dist[x+1][y+1]>d+1){
            dist[x+1][y+1]=d+1;
            Q.push({x+1, y+1});
        }
    }
    return {KING, dist[end.first][end.second]};
}

ii knight(ii start, ii end, int color){
    std::queue<ii> Q;
    Q.push(start);
    dist[start.first][start.second]=0;
    while(!Q.empty()){
        ii coord=Q.front();
        Q.pop();
        int x=coord.first, y=coord.second;
        int d=dist[x][y];
        if(x>1 && y>0 && dist[x-2][y-1]>d+1){
            if(col[x-2][y-1]!=color){
                dist[x-2][y-1]=d+1;
                Q.push({x-2, y-1});
            }
        }
        if(x<N-2 && y>0 && dist[x+2][y-1]>d+1){
            if(col[x+2][y-1]!=color){
                dist[x+2][y-1]=d+1;
                Q.push({x+2, y-1});
            }
        }
        if(x<N-1 && y>1 && dist[x+1][y-2]>d+1){
            if(col[x+1][y-2]!=color){
                dist[x+1][y-2]=d+1;
                Q.push({x+1, y-2});
            }
        }
        if(x>0 && y>1 && dist[x-1][y-2]>d+1){
            if(col[x-1][y-2]!=color){
                dist[x-1][y-2]=d+1;
                Q.push({x-1, y-2});
            }
        }
        if(x>1 && y<M-1 && dist[x-2][y+1]>d+1){
            if(col[x-2][y+1]!=color){
                dist[x-2][y+1]=d+1;
                Q.push({x-2, y+1});
            }
        }
        if(x<N-2 && y<M-1 && dist[x+2][y+1]>d+1){
            if(col[x+2][y+1]!=color){
                dist[x+2][y+1]=d+1;
                Q.push({x+2, y+1});
            }
        }
        if(x<N-1 && y<M-2 && dist[x+1][y+2]>d+1){
            if(col[x+1][y+2]!=color){
                dist[x+1][y-2]=d+1;
                Q.push({x+1, y+2});
            }
        }
        if(x>0 && y<M-2 && dist[x-1][y+2]>d+1){
            if(col[x-1][y+2]!=color){
                dist[x-1][y+2]=d+1;
                Q.push({x-1, y+2});
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            std::cout<<dist[i][j]<<" ";
        std::cout<<"\n";
    }
    return {KNIGHT, dist[end.first][end.second]};
}

void solve(){
    std::cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            std::cin>>board[i][j];
            if(board[i][j]==WKING)
                kwhite={i, j};
            if(board[i][j]==BKING)
                kblack={i, j};
            if(board[i][j]>='a' && board[i][j]<='z')
                col[i][j]=-1;
            else if(board[i][j]==SPACE)
                col[i][j]=0;
            else col[i][j]=1;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j]==SPACE) continue;
            for(int i=0;i<N;i++)
                for(int j=0;j<M;j++)
                    dist[i][j]=INFTY;
            iii res;
            if(board[i][j]==WROOK)
                res={0, rook({i, j}, kblack, col[i][j])};
            if(board[i][j]==BROOK)
                res={1, rook({i, j}, kwhite, col[i][j])};
            if(board[i][j]==WQUEEN)
                res={0, queen({i, j}, kblack, col[i][j])};
            if(board[i][j]==BQUEEN)
                res={1, queen({i, j}, kwhite, col[i][j])};
            if(board[i][j]==WKNIGHT)
                res={0, knight({i, j}, kblack, col[i][j])};
            if(board[i][j]==BKNIGHT)
                res={1, knight({i, j}, kwhite, col[i][j])};
            if(board[i][j]==WKING)
                res={0, king({i, j}, kblack, col[i][j])};
            if(board[i][j]==BKING)
                res={1, king({i, j}, kwhite, col[i][j])};
            if(board[i][j]==WBISH)
                res={0, bishop({i, j}, kblack, col[i][j])};
            if(board[i][j]==BBISH)
                res={1, bishop({i, j}, kwhite, col[i][j])};
            std::cout<<res.first<<" "<<res.second.first<<" "<<res.second.second<<"\n";
        }
    }
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
        solve();
}

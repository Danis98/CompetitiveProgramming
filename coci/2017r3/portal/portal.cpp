#include <bits/stdc++.h>

#define INFTY 1000000000

typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;

int N, M;
ii posC, posF;
char grid[500][500];
int walld[500][500], dist[500][500];

void dijkstra(){
    std::priority_queue<iii, std::vector<iii>, std::greater<iii>> Q;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            dist[i][j]=INFTY;
    Q.push({0, posC});
    dist[posC.first][posC.second]=0;
    while(!Q.empty()){
        iii cur=Q.top();
        Q.pop();
        int d=cur.first;
        int r=cur.second.first;
        int c=cur.second.second;
        if(dist[r][c]<d) continue;
        // normal steps
        if(r>0 && grid[r-1][c]!='#' && dist[r-1][c]>dist[r][c]+1){
            dist[r-1][c]=dist[r][c]+1;
            Q.push({d+1, {r-1, c}});
        }
        if(c>0 && grid[r][c-1]!='#' && dist[r][c-1]>dist[r][c]+1){
            dist[r][c-1]=dist[r][c]+1;
            Q.push({d+1, {r, c-1}});
        }
        if(r<N-1 && grid[r+1][c]!='#' && dist[r+1][c]>dist[r][c]+1){
            dist[r+1][c]=dist[r][c]+1;
            Q.push({d+1, {r+1, c}});
        }
        if(c<M-1 && grid[r][c+1]!='#' && dist[r][c+1]>dist[r][c]+1){
            dist[r][c+1]=dist[r][c]+1;
            Q.push({d+1, {r, c+1}});
        }
        // portals lol
        int rw, cw;
        // up
        rw=r;
        cw=c;
        while(grid[rw-1][cw]!='#') rw--;
        if(dist[rw][cw]>dist[r][c]+walld[r][c]){
            dist[rw][cw]=dist[r][c]+walld[r][c];
            Q.push({dist[rw][cw], {rw, cw}});
        }
        // down
        rw=r;
        cw=c;
        while(grid[rw+1][cw]!='#') rw++;
        if(dist[rw][cw]>dist[r][c]+walld[r][c]){
            dist[rw][cw]=dist[r][c]+walld[r][c];
            Q.push({dist[rw][cw], {rw, cw}});
        }
        // left
        rw=r;
        cw=c;
        while(grid[rw][cw-1]!='#') cw--;
        if(dist[rw][cw]>dist[r][c]+walld[r][c]){
            dist[rw][cw]=dist[r][c]+walld[r][c];
            Q.push({dist[rw][cw], {rw, cw}});
        }
        // right
        rw=r;
        cw=c;
        while(grid[rw][cw+1]!='#') cw++;
        if(dist[rw][cw]>dist[r][c]+walld[r][c]){
            dist[rw][cw]=dist[r][c]+walld[r][c];
            Q.push({dist[rw][cw], {rw, cw}});
        }
    }
}

void get_walld(){
    std::queue<ii> Q;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(grid[i][j]=='#'){walld[i][j]=0; Q.push({i, j});}
            else walld[i][j]=INFTY;
    while(!Q.empty()){
        ii cur=Q.front();
        Q.pop();
        int r=cur.first;
        int c=cur.second;
        if(r>0 && walld[r-1][c]>walld[r][c]+1){
            walld[r-1][c]=walld[r][c]+1;
            Q.push({r-1, c});
        }
        if(c>0 && walld[r][c-1]>walld[r][c]+1){
            walld[r][c-1]=walld[r][c]+1;
            Q.push({r, c-1});
        }
        if(r<N-1 && walld[r+1][c]>walld[r][c]+1){
            walld[r+1][c]=walld[r][c]+1;
            Q.push({r+1, c});
        }
        if(c<M-1 && walld[r][c+1]>walld[r][c]+1){
            walld[r][c+1]=walld[r][c]+1;
            Q.push({r, c+1});
        }
    }
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            std::cin>>grid[i][j];
            if(grid[i][j]=='C') posC={i, j};
            if(grid[i][j]=='F') posF={i, j};
        }

    get_walld();
    dijkstra();
    if(dist[posF.first][posF.second]==INFTY) std::cout<<"nemoguce\n";
    else std::cout<<dist[posF.first][posF.second]<<"\n";
}

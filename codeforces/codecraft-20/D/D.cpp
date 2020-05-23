#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

#define NULLP std::make_pair(-1, -1)

int N;
std::vector<std::vector<ii>> fin, grp;
std::vector<std::vector<char>> board;
std::set<ii> sinks;

void dfs(ii n, ii g, char move){
    if(fin[n.first][n.second] != g || grp[n.first][n.second] != NULLP) return;
    grp[n.first][n.second] = g;
    board[n.first][n.second] = move;

    if(n.first > 0) dfs({n.first-1, n.second}, g, 'D');
    if(n.first < N-1) dfs({n.first+1, n.second}, g, 'U');
    if(n.second > 0) dfs({n.first, n.second-1}, g, 'R');
    if(n.second < N-1) dfs({n.first, n.second+1}, g, 'L');
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    scanf("%d", &N);
    fin.assign(N, std::vector<ii> (N));
    grp.assign(N, std::vector<ii> (N, NULLP));
    board.assign(N, std::vector<char> (N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a, b;
            scanf("%d %d", &a, &b);
            if(a == -1 && b == -1) fin[i][j] = {a, b};
            else{
                a--;
                b--;
                sinks.insert({a, b});
                fin[i][j] = {a, b};
            }
        }
    }
    for(ii sink : sinks){
        if(fin[sink.first][sink.second] == NULLP) continue;
        dfs(sink, sink, 'X');
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(fin[i][j] != grp[i][j]){
                std::cout<<"INVALID\n";
                return 0;
            }
            if(fin[i][j] == NULLP){
                bool has_neigh = false;
                if(i > 0 && fin[i-1][j] == NULLP){
                    board[i][j] = 'U';
                    continue;
                }
                if(i < N-1 && fin[i+1][j] == NULLP){
                    board[i][j] = 'D';
                    continue;
                }
                if(j > 0 && fin[i][j-1] == NULLP){
                    board[i][j] = 'L';
                    continue;
                }
                if(j < N-1 && fin[i][j+1] == NULLP){
                    board[i][j] = 'R';
                    continue;
                }

                std::cout<<"INVALID\n";
                return 0;
            }
        }
    }
    std::cout<<"VALID\n";

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
}

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++){
        std::cout<<"Case #"<<t<<": ";
        int R, C;
        std::cin>>R>>C;
        std::vector<std::vector<ll>> board(R, std::vector<ll>(C));
        std::vector<std::vector<ll>> l(R, std::vector<ll>(C));
        std::vector<std::vector<ll>> r(R, std::vector<ll>(C));
        std::vector<std::vector<ll>> u(R, std::vector<ll>(C));
        std::vector<std::vector<ll>> d(R, std::vector<ll>(C));
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                std::cin>>board[i][j];
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++){
                u[i][j] = i==0 ? -1 : (i-1);
                d[i][j] = i==R-1 ? -1 : (i+1);
                l[i][j] = j==0 ? -1 : (j-1);
                r[i][j] = j==C-1 ? -1 : (j+1);
            }
        ll tot = 0;
        for(int i=0;i<R*C;i++) tot += board[i/C][i%C];
        ll turn_s = tot;
        std::vector<std::vector<bool>> alive(R, std::vector<bool>(C, true));
        std::set<ii> q, nxt_q;

        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                q.insert({i, j});

        bool run;
        do{
            run = false;
            for(ii coord : q){
                int i = coord.fi, j = coord.se;
                ll cnt = 0, sum = 0;
                if(u[i][j] != -1){ cnt++; sum += board[u[i][j]][j]; }
                if(d[i][j] != -1){ cnt++; sum += board[d[i][j]][j]; }
                if(l[i][j] != -1){ cnt++; sum += board[i][l[i][j]]; }
                if(r[i][j] != -1){ cnt++; sum += board[i][r[i][j]]; }
                // std::cout<<"["<<i<<" "<<j<<" "<<board[i][j]<<" "<<((double)sum/cnt)<<"]\n";
                if(cnt * board[i][j] < sum){
                    turn_s -= board[i][j];
                    alive[i][j] = false;
                    run = true;
                }
            }
            for(ii coord : q){
                int i = coord.fi, j = coord.se;
                if(!alive[i][j]){
                    // std::cout<<"{"<<i<<" "<<j<<"}\n";
                    if(d[i][j] != -1){ u[d[i][j]][j] = u[i][j]; nxt_q.insert({d[i][j], j}); }
                    if(u[i][j] != -1){ d[u[i][j]][j] = d[i][j]; nxt_q.insert({u[i][j], j}); }
                    if(l[i][j] != -1){ r[i][l[i][j]] = r[i][j]; nxt_q.insert({i, l[i][j]}); }
                    if(r[i][j] != -1){ l[i][r[i][j]] = l[i][j]; nxt_q.insert({i, r[i][j]}); }
                }
            }
            q = nxt_q;
            nxt_q = std::set<ii>();

            if(run) tot += turn_s;
        }while(run);

        std::cout<<tot<<"\n";
    }
}

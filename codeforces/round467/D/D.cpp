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

int N, M;
std::vector<std::vector<int>> G;
bool can_win = false, can_tie = false;
std::vector<ll2> vis;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M;
    std::cin>>N>>M;
    G.resize(N);
    vis.assign(N, {-1, -1});
    for(int i=0;i<N;i++){
        int c, v;
        std::cin>>c;
        G[i].resize(c);
        for(int j=0;j<c;j++) std::cin>>G[i][j];
        for(int j=0;j<c;j++) G[i][j]--;
    }
    int s;
    std::cin>>s;
    s--;

    std::queue<ll2> Q;
    Q.push({s, 0});
    vis[s] = {0, -1};
    std::vector<ll2> par(N, {-1, -1});
    int winner = -1;
    while(!Q.empty()){
        ll2 cur = Q.front();
        Q.pop();
        int n = cur.fi;
        int d = cur.se;
        int p = d % 2;
        if(G[n].size() == 0){
            if(p == 1){
                winner = n;
                can_win = true;
            }
        }
        for(int neigh : G[n]){
            if(p == 0){
                if(vis[neigh].se != -1 && vis[neigh].se < d){
                    can_tie = true;
                    continue;
                }
                else if(vis[neigh].se != -1) continue;
                std::cout<<n<<",0->"<<neigh<<",1\n";
                vis[neigh].se = d;
                par[neigh].se = n;
                Q.push({neigh, d+1});
            }
            if(p == 1){
                if(vis[neigh].fi != -1 && vis[neigh].fi < d){
                    can_tie = true;
                    continue;
                }
                else if(vis[neigh].fi != -1) continue;
                std::cout<<n<<",1->"<<neigh<<",0\n";
                vis[neigh].fi = d;
                par[neigh].fi = n;
                Q.push({neigh, d+1});
            }
        }
    }

    // std::cout<<can_win<<" "<<can_tie<<"\n";
    // for(int i=0;i<N;i++) std::cout<<par[i].fi<<" "<<par[i].se<<"\n";

    if(can_win){
        std::cout<<"Win\n";
        int n = winner;
        int p = 1;
        std::vector<int> path;
        while(n != -1){
            path.pb(n);
            // std::cout<<n<<"->";
            n = p == 0 ? par[n].fi : par[n].se;
            // std::cout<<n<<"\n";
            p = 1-p;
        }
        for(int i=path.size()-1;i>=0;i--) std::cout<<path[i]+1<<" ";
        std::cout<<"\n";
    }
    else if(can_tie) std::cout<<"Draw\n";
    else std::cout<<"Lose\n";
}

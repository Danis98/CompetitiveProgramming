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

ll N;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N;

    std::vector<std::vector<ll>> v(N, std::vector<ll>(N));
    std::vector<std::vector<bool>> taken(N, std::vector<bool>(N, true));

    for(ll i=0;i<N;i++)
        for(ll j=0;j<N;j++)
            v[i][j] = std::min(std::min(i, N-i-1), std::min(j, N-j-1));

    ll res = 0;

    for(int i=0;i<N*N;i++){
        ll idx;
        std::cin>>idx;
        idx--;
        ll sr = idx/N, sc = idx%N;
        std::queue<ll3> Q;
        Q.push({0, {sr, sc}});
        std::set<ll2> vis;
        while(!Q.empty()){
            ll3 cur = Q.front();
            Q.pop();
            ll d = cur.fi;
            ll r = cur.se.fi, c = cur.se.se;
            if(vis.find(cur.se) != vis.end()) continue;
            vis.insert(cur.se);
            if(r == 0 || r == N-1 || c == 0 || c == N-1){
                v[sr][sc] = std::min(v[sr][sc], d);
                continue;
            }
            if(d >= v[sr][sc]) continue;
            Q.push({d+taken[r-1][c], {r-1, c}});
            Q.push({d+taken[r+1][c], {r+1, c}});
            Q.push({d+taken[r][c-1], {r, c-1}});
            Q.push({d+taken[r][c+1], {r, c+1}});
        }
        res += v[sr][sc];
        taken[sr][sc] = false;
    }

    // for(int i=0;i<N;i++)
    //     for(int j=0;j<N;j++)
    //         std::cout<<v[i][j]<<" \n"[j==N-1];

    std::cout<<res<<"\n";
}

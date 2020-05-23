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

ll N, M;
std::vector<std::vector<ll>> G;
std::vector<ll> dist, prev;
std::vector<ll2> edges;

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
        std::cin>>N>>M;
        G.resize(N);
        dist.assign(N, -1);
        prev.assign(N, -1);
        edges.clear();
        bool pos = false, neg = false;
        prev[0] = 0;
        dist[0] = 0;
        for(int i=1;i<N;i++){
            ll v;
            std::cin>>v;
            pos |= v > 0;
            neg |= v < 0;
            if(v > 0) dist[i] = v;
            else prev[i] = -v;
        }
        for(int i=0;i<M;i++){
            ll a, b;
            std::cin>>a>>b;
            a--;
            b--;
            edges.pb({a, b});
            G[a].pb(b);
            G[b].pb(a);
        }
        if(pos && neg){
            for(int i=0;i<M;i++) std::cout<<"-1 ";
            std::cout<<"\n";
        }
        else if(neg){
            for(int i=0;i<N;i++)
                dist[i] = prev[i];
            for(int i=0;i<M;i++){
                ll p1 = dist[edges[i].fi], p2 = dist[edges[i].se];
                std::cout<<std::max(1LL, std::abs(p1-p2))<<" ";
            }
            std::cout<<"\n";
        }
        // std::priority_queue<ll2, std::vector<ll2>, std::greater<ll2>> Qpre, Qdist;
        // dist[0] = 0;
        // for(int i=0;i<N;i++)
        //     if(prev[i] != -1) Qpre.push({pre[i], i});
        // for(ll neigh : G[0])
        //     if(dist[neigh])
        // ll cur_time = 1;
        // ll done = 1;
        // while(!Qpre.empty()){
        //     ll2 cur = Qpre.top();
        //     ll req = cur.fi;
        //     ll n = cur.se;
        //
        // }
    }
}

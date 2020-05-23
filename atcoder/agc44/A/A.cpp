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
    while(T--){
        ll N, A, B, C, D;
        std::cin>>N>>A>>B>>C>>D;
        std::priority_queue<ll2, std::vector<ll2>, std::greater<ll2>> Q;
        std::unordered_set<ll> vis;
        Q.push({0, N});
        ll res = D * N;
        if(res < 0) res = LLONG_MAX;
        while(!Q.empty()){
            ll2 cur = Q.top();
            Q.pop();
            if(vis.find(cur.se) != vis.end()) continue;
            vis.insert(cur.se);
            // std::cout<<cur.fi<<" "<<cur.se<<"\n";
            if(cur.se == 1){
                res = std::min(res, cur.fi + D);
                break;
            }
            if(cur.fi+cur.se*D > 0)
                res = std::min(res, cur.fi+cur.se*D);
            std::vector<ll2> div(3);
            div[0] = {2, A}; div[1] = {3, B}; div[2] = {5, C};
            for(ll2 d : div){
                if(cur.se%d.fi == 0) Q.push({cur.fi+d.se, cur.se/d.fi});
                else{
                    ll del1 = cur.se % d.fi;
                    ll del2 = (d.fi - del1) % d.fi;
                    Q.push({cur.fi+d.se+del1*D, (cur.se-del1)/d.fi});
                    Q.push({cur.fi+d.se+del2*D, (cur.se+del2)/d.fi});
                }
            }
        }
        std::cout<<res<<"\n";
    }
}

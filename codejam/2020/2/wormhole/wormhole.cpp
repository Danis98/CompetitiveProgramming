#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef long double ld;
typedef std::pair<double, double> dd;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll2 get_dir(ll2 p1, ll2 p2){
    ll2 res = {p1.se-p2.se, p1.fi-p2.fi};
    if(res.fi < 0){
        res.fi *= -1;
        res.se *= -1;
    }
    if(res.fi == 0) res.se = 1;
    if(res.se == 0) res.fi = 1;
    ll v = gcd(std::abs(res.fi), std::abs(res.se));
    return {res.fi/v, res.se/v};
}

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
        ll N;
        std::cin>>N;
        std::vector<ll2> points(N);
        for(int i=0;i<N;i++)
            std::cin>>points[i].fi>>points[i].se;
        std::set<ll2> dirs;
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
                dirs.insert(get_dir(points[i], points[j]));
        if(dirs.size() == 0){
            std::cout<<"1\n";
            continue;
        }
        ll res = 0;
        for(ll2 dir : dirs){
            std::vector<ll> groups;
            ll cnt = 0, ones = 0;
            for(int i=0;i<N;i++){
                bool aligned = false;
                for(int j=0;j<N;j++){
                    if(i == j) continue;
                    if(get_dir(points[i], points[j]) == dir){
                        aligned = true;
                        break;
                    }
                }
                if(!aligned) ones++;
            }
            // std::cout<<ones<<"\n";
            cnt = N - ones;
            cnt += std::min(2LL, ones);
            res = std::max(res, cnt);
            std::cout<<"("<<dir.fi<<", "<<dir.se<<") -> "<<cnt<<"\n";
        }
        std::cout<<res<<"\n";
    }
}

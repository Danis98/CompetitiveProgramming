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

std::vector<ll> a;
int ctr;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        ll N;
        std::cin>>N;
        a.assign(N, 0);
        ctr = 1;
        std::priority_queue<ll2> Q;
        Q.push({N, 0});
        while(!Q.empty()){
            ll2 cur = Q.top();
            Q.pop();
            ll l = -cur.se;
            ll r = l + cur.fi - 1;
            ll mid = (l + r)/2;
            a[mid] = ctr++;
            if(l < mid) Q.push({mid-l, -l});
            if(mid < r) Q.push({r-mid, -mid-1});
        }

        for(int i=0;i<N;i++)
            std::cout<<a[i]<<" \n"[i==N-1];
    }
}

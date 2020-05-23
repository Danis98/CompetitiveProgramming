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

    ll N;
    std::cin>>N;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    std::vector<ll> pre(N);
    pre[0] = a[0];
    for(int i=1;i<N;i++) pre[i] = a[i] + pre[i-1];
    ll res = 0;
    std::map<ll, ll> pos;
    ll lim_so_far = N;
    for(int i=N-1;i>=0;i--){
        ll v = i==0 ? 0 : pre[i-1];
        if(a[i] == 0){
            lim_so_far = i;
        }
        else{
            if(pos.find(v) == pos.end()) res += lim_so_far - i;
            else{
                lim_so_far = std::min(pos[v], lim_so_far);
                res += lim_so_far - i;
            }
        }
        pos[pre[i]] = i;
        // std::cout<<"["<<res<<"]\n";
    }
    std::cout<<res<<"\n";
}

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;
typedef long double ld;

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
    std::vector<ll> pre1(N, 0), pre2(N, 0);
    for(int i=0;i<N;i++){
        if(i>0){
            pre1[i] = pre1[i-1];
            pre2[i] = pre2[i-1];
        }
        if(a[i] == 1) pre1[i]++;
        else pre2[i]++;
    }
    std::vector<ll> p1_inv(N+2, -1), p2_inv(N+2, -1);
    for(int i=0;i<N;i++){
        if(p1_inv[pre1[i]] == -1) p1_inv[pre1[i]] = i;
        if(p2_inv[pre2[i]] == -1) p2_inv[pre2[i]] = i;
    }

    std::vector<ll2> comb;
    for(ll s=N;s>=1;s--){
        ll start = -1;
        ll t1 = 0, t2 = 0;
        bool valid = true;
        ll last = -1;
        while(start < N-1){
            ll n1 = p1_inv[std::min((start!=-1?pre1[start]:0)+s, N+1)];
            ll n2 = p2_inv[std::min((start!=-1?pre2[start]:0)+s, N+1)];
            if(n1 == -1 && n2 == -1){
                valid = false;
                break;
            }
            else if(n1 == -1 || n1 > n2 && n2 != -1){
                t2++;
                start = n2;
                last = 2;
            }
            else{
                t1++;
                start = n1;
                last = 1;
            }
        }
        if(!valid || t1 == t2) continue;
        if(last == 1 && t1 > t2) comb.pb({t1, s});
        else if(last == 2 && t2 > t1) comb.pb({t2, s});
    }

    std::sort(comb.begin(), comb.end());

    std::cout<<comb.size()<<"\n";
    for(ll2 c : comb)
        std::cout<<c.fi<<" "<<c.se<<"\n";
}

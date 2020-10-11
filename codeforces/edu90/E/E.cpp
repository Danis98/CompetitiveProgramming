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
        ll N, K;
        std::cin>>N>>K;
        ll res = -1;
        for(int s=0;s<10;s++){
            ll last = 0;
            for(int i=0;i<=K;i++)
                last += (s+i)%10;
            if(s+K<10){
                for(int a=0;a<=9;a++){
                    if(((N-last)/(K+1)-a) < 0 || ((N-last)/(K+1)-a) % 9 != 0) continue;
                    ll x = ((N-last)/(K+1)-a)/9;
                    if((K+1)*(a+9*x)+last != N) continue;
                    // std::cout<<s<<" "<<a<<" "<<x<<" "<<last<<"\n";
                    ll r = a;
                    for(int i=0;i<x;i++) r = 10*r + 9;
                    r = 10*r+s;
                    if(res == -1 || res > r)
                        res = r;
                }
            }
            else{
                for(int a=0;a<=9;a++){
                    ll v1 = N - last - (s+K-9)*(a+1);
                    if(v1 < 0 || v1%(10-s) != 0) continue;
                    ll v2 = v1 / (10-s) - a;
                    if(v2 < 0 || v2%9 != 0) continue;
                    ll x = v2 / 9;
                    ll val = (10-s)*(a+9*x)+(s+K-9)*(a+1)+last;
                    if(val != N) continue;
                    ll r = a;
                    for(int i=0;i<x;i++) r = 10*r+9;
                    r = 10*r+s;
                    if(res == -1 || res > r)
                        res = r;
                }
            }
            // ll mid = std::max(0LL, s+K-9);
            // if(N < last+mid) continue;
            // ll pre = N - last - mid;
            // if(pre%(K+1)==0){
            //     ll rem = pre/(K+1);
            //     // std::cout<<"["<<s<<" "<<last<<" "<<rem<<"]\n";
            //     std::string S = "";
            //     while(rem){
            //         ll m = std::min(rem, 9LL);
            //         S += m + '0';
            //         rem -= m;
            //         std::reverse(S.begin(), S.end());
            //     }
            //     std::cout<<S<<(S.length()==0 || mid == 0?"":"0");
            //     if(K != 0 || s != 0) std::cout<<s;
            //     std::cout<<"\n";
            //     found = true;
            //     break;
            // }
        }
        std::cout<<res<<"\n";
    }
}

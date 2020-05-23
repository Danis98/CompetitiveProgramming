#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;
typedef long double lld;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);

    lld K, D, T;
    std::cin>>K>>D>>T;
    lld val_on = (lld)1/T;
    lld val_off = (lld)0.5/T;

    // std::cout<<val_on<<" "<<val_off<<"\n";

    lld cyc_len = D*ceil(K/D);
    lld cyc_val = val_on * K + val_off * (cyc_len - K);
    // std::cout<<cyc_len<<"\n";
    // std::cout<<cyc_val<<"\n";
    lld cyc_num = floor(1.0/cyc_val);
    // std::cout<<cyc_num<<"\n";
    lld rem = 1 - cyc_num * cyc_val;
    lld time = cyc_num * cyc_len;
    // std::cout<<rem<<" "<<(K*val_on)<<"\n";
    if(rem <= K * val_on) {time += rem / val_on; rem = 0;}
    else{rem -= K*val_on; time += K;}
    time += rem / val_off;
    printf("%.09f\n", (double)time);
}

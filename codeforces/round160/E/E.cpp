#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define MAXP 50

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // std::map<ll, ll> freq;

    // for(int m=127-1;m<=127-1;m++){
    //     int a[m+1][m+1];
    //     for(int i=0;i<m;i++) a[0][i] = 0;
    //     a[0][m] = 1;
    //     for(int i=1;i<=m;i++){
    //         for(int j=0;j<=m;j++){
    //             if(j == 0) a[i][j] = a[i-1][j+1];
    //             else if(j == m) a[i][j] = a[i-1][j-1];
    //             else a[i][j] = a[i-1][j-1] ^ a[i-1][j+1];
    //         }
    //     }
    //
    //     // for(int i=0;i<=m;i++){
    //     //     ll tot = 0;
    //     //     for(int j=0;j<=m;j++)
    //     //         tot += a[i][j];
    //     //     freq[tot]++;
    //     // }
    //
    //     for(int i=0;i<=m;i++){
    //         for(int j=0;j<=m;j++) std::cout<<(a[i][j]?"█":" ");
    //         std::cout<<"\n";
    //     }
    //     std::cout<<"\n";
    // }

    std::vector<ll> pow2(MAXP);
    for(int i=0;i<MAXP;i++) pow2[i] = 1LL << i;

    ll N, T;
    std::cin>>N>>T;

    int idx = -1;
    for(int i=0;i<MAXP;i++){
        if(T == pow2[i]){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        std::cout<<"0\n";
        return 0;
    }

    std::vector<std::vector<ll>> freq(MAXP, std::vector<ll>(MAXP, 0));
    freq[0][0] = 1;
    for(int i=1;i<MAXP;i++)
        for(int j=0;j<MAXP;j++)
            freq[i][j] = freq[i-1][j] + (j == 0 ? 0 : freq[i-1][j-1]);

    // for(int i=0;i<MAXP;i++){
    //     for(int j=0;j<MAXP;j++)
    //         std::cout<<freq[i][j]<<" ";
    //     std::cout<<"\n";
    // }

    ll tot = 0;
    ll cum = 1;
    ll p = 0;
    while(cum <= N){
        tot += freq[p][idx];
        std::cout<<p<<" "<<(1LL<<p)<<" "<<freq[p][idx]<<std::endl;
        p++;
        cum += 1LL << p;
    }


    std::cout<<tot<<"\n";
}

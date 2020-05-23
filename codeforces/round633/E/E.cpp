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

std::string base4enc(ll n){
    std::string s = "";
    while(n){
        s += '0' + n%4;
        n >>= 2;
    }
    std::reverse(s.begin(), s.end());
    return s;
}

ll base4dec(std::string s){
    ll n = 0;
    ll mul = 1;
    for(int i=s.length()-1;i>=0;i--){
        n += (ll)(s[i]-'0') * mul;
        mul *= 4LL;
    }
    return n;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // int N = 200;
    // int MAXN = 10000;
    // std::vector<bool> taken(MAXN+1, false);
    // for(int i=0;i<N;i++){
    //     int a=-1, b=-1, c;
    //     for(int j=1;j<=MAXN;j++)
    //         if(!taken[j]){
    //             a = j;
    //             break;
    //         }
    //     if(a == -1){
    //         std::cout<<"AAARGH\n";
    //         break;
    //     }
    //     for(int j=a+1;j<=MAXN;j++)
    //         if(!taken[j] && !taken[a^j]){
    //             b = j;
    //             c = a ^ b;
    //             break;
    //         }
    //     if(b == -1){
    //         std::cout<<"AAARGH2\n";
    //         break;
    //     }
    //     taken[a] = taken[b] = taken[c] = true;
    //     std::cout<<base4enc(a)<<" "<<base4enc(b)<<" "<<base4enc(c)<<"\n";
    // }

    std::vector<ll> beg(32);
    beg[0] = 1;
    for(int i=1;i<32;i++)
        beg[i] = beg[i-1] + 3*(1LL << (2*i-2));
    int seq[3][4] = {
        {0, 1, 2, 3},
        {0, 2, 3, 1},
        {0, 3, 1, 2}
    };

    int T;
    std::cin>>T;
    while(T--){
        ll N;
        std::cin>>N;

        ll dig = 0;
        while(beg[dig] <= N) dig++;
        dig--;
        ll delta = N - beg[dig];
        delta /= 3;
        // std::cout<<N<<" "<<dig<<" "<<delta<<"\n";
        std::string s = base4enc(delta);
        while(s.length() < dig) s = '0' + s;
        for(int i=0;i<dig;i++) s[i] = seq[(N-1)%3][s[i]-'0']+'0';
        s = (char)(((N-1)%3)+'1') + s;
        std::cout<<base4dec(s)<<"\n";
    }
}

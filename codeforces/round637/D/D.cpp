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

ll weight(ll n){
    return ((n>>0)&1) + ((n>>1)&1) + ((n>>2)&1) + ((n>>3)&1) + ((n>>4)&1) + ((n>>5)&1) + ((n>>6)&1);
}

ll dist(ll a, ll b){
    if((a & b) != a) return -1;
    return weight(a ^ b);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll N, K;
    std::cin>>N>>K;
    std::vector<ll> a(N, 0);
    std::vector<std::vector<ll>> dig(N, std::vector<ll>(K+1, -1));
    for(int i=0;i<N;i++){
        std::string s;
        std::cin>>s;
        for(int j=0;j<s.length();j++)
            a[i] += (s[j]-'0') << (s.length()-j-1);
    }

    std::vector<ll> num(10), num_inv(1<<8, -1);
    std::vector<std::string> enc = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    for(int i=0;i<10;i++){
        num[i] = std::stoi(enc[i], 0, 2);
        num_inv[std::stoi(enc[i], 0, 2)] = i;
    }

    for(int i=N-1;i>=0;i--){
        for(int j=0;j<=K;j++){
            for(int k=0;k<10;k++){
                ll d = dist(a[i], num[k]);
                if(d == -1 || j < d) continue;
                if(i == N-1 && j == d) dig[i][j] = k;
                else if(i != N-1 && dig[i+1][j-d] != -1) dig[i][j] = k;
            }
        }
    }

    // for(int i=0;i<N;i++)
    //     for(int j=0;j<=K;j++)
    //         std::cout<<dig[i][j]<<" \n"[j==K];

    ll w = K;
    for(int i=0;i<N;i++){
        std::cout<<dig[i][w];
        if(dig[i][w] == -1) break;
        w -= dist(a[i], num[dig[i][w]]);
    }
    std::cout<<"\n";
}

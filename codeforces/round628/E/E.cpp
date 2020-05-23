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

int not_prime[1000001];
int freq[1000001];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i=2;i<=1000;i++){
        int n = i * i;
        if(not_prime[i]) continue;
        while(n <= 1000000){
            not_prime[n] = 1;
            n *= i;
        }
    }

    std::cin>>

    int a = 0, b = N;
}

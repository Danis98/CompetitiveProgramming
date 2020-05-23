#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N, M;
    std::cin>>N>>M;
    std::vector<ll> a(N), freq(M, 0);
    for(int i=0;i<N;i++){
        std::cin>>a[i];
        freq[a[i] % M]++;
        if(freq[a[i] % M] > 1){
            std::cout<<"0\n";
            return 0;
        }
    }
    ll res = 1;
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
            res = (res * std::abs(a[i] - a[j]) % M) % M;
    std::cout<<res<<"\n";
}

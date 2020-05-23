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

    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
        int A, B, P;
        std::string S;
        std::cin>>A>>B>>P>>S;
        int N = S.length();
        std::vector<ll> cost(N);
        cost[N-1] = 0LL;
        cost[N-2] = S[N-2] == 'A' ? A : B;
        int idx = cost[N-2] > P ? N-1 : N-2;
        for(int i=N-3;i>=0;i--){
            if(S[i] != S[i+1]) cost[i] = cost[i+1] + (S[i] == 'A' ? A : B);
            else cost[i] = cost[i+1];
            if(cost[i] <= P) idx = i;
        }
        std::cout<<(idx+1)<<"\n";
    }
}

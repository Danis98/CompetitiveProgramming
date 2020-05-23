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

    int N;
    std::cin>>N;
    std::vector<ll> b(N);
    for(int i=0;i<N;i++) std::cin>>b[i];
    std::map<ll, ll> scores;
    ll max_score = 0;
    for(int i=0;i<N;i++){
        scores[b[i] - i] += b[i];
        max_score = std::max(max_score, scores[b[i] - i]);
    }
    std::cout<<max_score<<"\n";
}

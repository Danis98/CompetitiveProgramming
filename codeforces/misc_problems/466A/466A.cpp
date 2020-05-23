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

    ll N, M, A, B;
    std::cin>>N>>M>>A>>B;

    if(M*A < B) std::cout<<N*A<<"\n";
    else if((N%M)*A < B) std::cout<<(B*(N/M)+A*(N%M))<<"\n";
    else std::cout<<(B*(N/M+1))<<"\n";
}

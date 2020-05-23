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

    int N;
    std::cin>>N;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    ll sc[2] = {0, 0};
    int p1 = 0, p2 = N-1;
    for(int i=0;i<N;i++){
        if(a[p1] > a[p2]) sc[i%2] += a[p1++];
        else sc[i%2] += a[p2--];
    }

    std::cout<<sc[0]<<" "<<sc[1]<<"\n";
}

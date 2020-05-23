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

ll N, A, R, M;
std::vector<ll> a;

ll get_cost(ll h){
    ll over = 0, sub = 0;
    ll cost = 0;
    for(int i=0;i<N;i++)
        if(a[i] < h) sub+=h-a[i];
        else if(a[i] > h) over+=a[i]-h;
    if(M > A + R) return sub*A + over*R;
    cost = M * std::min(over, sub);
    cost += A * (sub - std::min(over, sub));
    cost += R * (over - std::min(over, sub));
    return cost;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N>>A>>R>>M;
    a.resize(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    ll a = 0, b = 1000000000;
    while((b-a) > 2){
        // std::cout<<a<<" "<<b<<"\n";
        ll m1 = (2*a+b)/3, m2 = (a+2*b)/3;
        ll c1 = get_cost(m1), c2 = get_cost(m2);
        // std::cout<<"["<<m1<<"->"<<c1<<" "<<m2<<"->"<<c2<<"]"<<std::endl;
        if(c1 < c2) b = m2;
        else a = m1;
    }
    std::cout<<std::min(get_cost(a), std::min(get_cost(a+1), get_cost(a+2)))<<"\n";
}

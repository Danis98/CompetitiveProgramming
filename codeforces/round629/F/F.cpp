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

    int N, K;
    std::cin>>N>>K;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];

    std::sort(a.begin(), a.end());
    std::map<ll, int> freq;
    for(int i=0;i<N;i++) freq[a[i]]++;

    std::vector<ll> pre_cost(N, 0), post_cost(N, 0);
    std::vector<ll> more(N, 0), less(N, 0);

    for(int i=1;i<N;i++)
        if(a[i] != a[i-1]) less[i] = i;
        else less[i] = less[i-1];
    for(int i=N-2;i>=0;i--)
        if(a[i] != a[i+1]) more[i] = N - i - 1;
        else more[i] = more[i+1];

    for(int i=1;i<N;i++)
        pre_cost[i] = pre_cost[i-1] + less[i] * (a[i] - a[i-1]);

    for(int i=N-2;i>=0;i--)
        post_cost[i] = post_cost[i+1] + more[i] * (a[i+1] - a[i]);

    std::vector<ll> next(N, N-1), prev(N, 0);
    for(int i=1;i<N;i++)
        if(a[i] != a[i-1]) prev[i] = i-1;
        else prev[i] = prev[i-1];
    for(int i=N-2;i>=0;i--)
        if(a[i] != a[i+1]) next[i] = i+1;
        else next[i] = next[i+1];

    // for(int i=0;i<N;i++) std::cout<<pre_cost[i]<<" ";
    // std::cout<<"\n";
    // for(int i=0;i<N;i++) std::cout<<post_cost[i]<<" ";
    // std::cout<<"\n";
    // for(int i=0;i<N;i++) std::cout<<less[i]<<" ";
    // std::cout<<"\n";
    // for(int i=0;i<N;i++) std::cout<<more[i]<<" ";
    // std::cout<<"\n";

    ll min_cost = -1;
    for(int i=0;i<N;i++){
        ll needed = std::max(0, K - freq[a[i]]);
        if(needed == 0){
            min_cost = 0;
            break;
        }
        ll cost = needed;
        // std::cout<<cost<<"+";
        ll sub_cost = pre_cost[prev[i]] + (a[i] - a[prev[i]] - 1) * less[i];
        // std::cout<<sub_cost<<"/";
        ll over_cost = post_cost[next[i]] + (a[next[i]] - a[i] - 1) * more[i];
        // std::cout<<over_cost<<"=";
        if(less[i] < needed && more[i] < needed)
            cost += sub_cost + over_cost;
        else if(less[i] >= needed && more[i] >= needed)
            cost += std::min(sub_cost, over_cost);
        else if(less[i] < needed) cost += over_cost;
        else if(more[i] < needed) cost += sub_cost;
        // std::cout<<cost<<"\n";
        if(min_cost == -1 || cost < min_cost)
            min_cost = cost;
    }

    std::cout<<min_cost<<"\n";
}

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

typedef struct list_node{
    std::vector<ll> val;
    list_node *next;
} list_node;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll N, K;
    std::cin>>N>>K;
    std::vector<ll> freq(K+1, 0);
    std::vector<ll> m(N);
    for(int i=0;i<N;i++){
        std::cin>>m[i];
        // ll t;
        // std::cin>>t;
        // freq[t]++;
    }
    std::vector<ll> c(K+1);
    for(int i=0;i<K;i++) std::cin>>c[i+1];

    std::vector<std::vector<ll>> sol;

    std::sort(m.begin(), m.end());
    std::reverse(m.begin(), m.end());
    for(int i=0;i<N;i++){
        ll maxl = c[m[i]];
        if(sol.size() == 0 || sol[sol.size()-1].size() >= maxl){
            sol.pb(std::vector<ll>(1, m[i]));
            continue;
        }
        ll a = 0, b = sol.size()-1;
        while(a < b){
            ll mid = (a+b)/2;
            if(sol[mid].size() >= maxl) a = mid + 1;
            else b = mid;
        }
        sol[a].pb(m[i]);
    }

    // std::vector<std::vector<ll>> lst(N+1);
    // std::vector<ll> next(N+1, -1);
    // ll head = -1;
    // for(int i=0;i<N;i++){
    //     lst[c[m[i]]].pb(m[i]);
    // }
    // // for(int i=1;i<=N;i++){
    // //     std::cout<<i<<": ";
    // //     for(int j=0;j<lst[i].size();j++)
    // //         std::cout<<lst[i][j]<<" ";
    // //     std::cout<<std::endl;
    // // }
    // for(int i=1;i<=N;i++)
    //     if(lst[i].size() > 0){
    //         head = i;
    //         break;
    //     }
    // ll last_v = head;
    // for(int i=head+1;i<=N;i++){
    //     if(lst[i].size() > 0){
    //         next[last_v] = i;
    //         last_v = i;
    //     }
    // }
    //
    // std::vector<std::vector<ll>> sol;
    // while(N){
    //     std::vector<ll> subtask;
    //     ll cur_h = head;
    //     while(N && cur_h != -1){
    //         // std::cout<<N<<" "<<cur_h<<" "<<subtask.size()<<"\n";
    //         if(subtask.size() < cur_h){
    //             subtask.pb(lst[cur_h][lst[cur_h].size()-1]);
    //             lst[cur_h].pop_back();
    //             N--;
    //         }
    //         else cur_h = next[cur_h];
    //
    //         if(lst[cur_h].size() == 0){
    //             if(cur_h == head) head = next[head];
    //             cur_h = next[cur_h];
    //         }
    //     }
    //
    //     sol.pb(subtask);
    // }

    std::cout<<sol.size()<<"\n";
    for(auto sub : sol){
        std::cout<<sub.size()<<" ";
        for(int i=0;i<sub.size();i++)
            std::cout<<sub[i]<<" \n"[i==sub.size()-1];
    }
}

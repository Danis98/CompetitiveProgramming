#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll2, ll> ll3;
typedef std::pair<double, double> dd;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N;
    std::cin>>N;
    std::vector<ll> a(N), t(N);
    for(int i=0;i<N;i++) std::cin>>a[i];
    for(int i=0;i<N;i++) std::cin>>t[i];
    std::vector<ll2> ord(N);
    for(int i=0;i<N;i++) ord[i] = {a[i], t[i]};
    std::sort(ord.begin(), ord.end());
    ll tot_cost = 0LL;
    std::priority_queue<ll2> Q;
    ll pos = ord[0].first, idx = 0;
    for(int i=0;i<N;i++){
        while(idx < N && ord[idx].first <= pos){
            // std::cout<<"TAKING "<<idx<<" at "<<ord[idx].first<<"\n";
            Q.push({ord[idx].second, ord[idx].first});
            idx++;
        }
        ll2 cur = Q.top();
        Q.pop();
        // std::cout<<"POSITIONING "<<cur.second<<" TO "<<pos<<" FOR "<<cur.first<<" PER STEP\n";
        tot_cost += cur.first * (pos - cur.second);
        pos++;
        if(Q.empty() && idx < N) pos = ord[idx].first;
        // std::cout<<"NEXT POS IS "<<pos<<"\n";
    }
    std::cout<<tot_cost<<"\n";
}

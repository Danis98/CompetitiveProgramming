#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

struct disjoint_set{
    std::vector<int> p, rank;
    disjoint_set(int N){
        rank.assign(N, 0);
        p.assign(N, 0); for(int i=0;i<N;i++) p[i] = i;
    }
    int find(int a){return p[a] == a ? a : (p[a] = find(p[a]));}
    bool same_set(int a, int b){return find(a) == find(b);}
    void union_set(int a, int b){
        if(same_set(a, b)) return;
        int ra = find(a), rb = find(b);
        p[rb] = ra;
    }
};


int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll N, M;
    std::cin>>N>>M;

    disjoint_set disj(N+1);
    std::vector<ll> next(N+1, -1);
    std::vector<ll> res(N+1, 0);
    for(int i=1;i<N;i++) next[i] = i + 1;

    for(int i=0;i<M;i++){
        ll L, R, X;
        std::cin>>L>>R>>X;
        ll first_rep = disj.find(L);
        if(first_rep < L) first_rep = next[first_rep];
        ll cur = first_rep;
        while(cur != -1 && cur <= R){
            // std::cout<<cur<<"\n";
            if(cur != X) res[cur] = X;
            disj.union_set(X, cur);
            if(next[cur] == -1 || disj.find(next[cur]) == cur) break;
            cur = disj.find(next[cur]);
        }
        // std::cout<<"["<<cur<<"]\n";
        if(cur > R)
            next[X] = cur;

        // for(int j=1;j<=N;j++)
        //     std::cout<<disj.find(j)<<" \n"[j==N];
        // for(int j=1;j<=N;j++)
        //     std::cout<<res[j]<<" \n"[j==N];
        // for(int j=1;j<=N;j++)
        //     std::cout<<next[j]<<" \n"[j==N];
    }

    for(int i=1;i<=N;i++)
        std::cout<<res[i]<<" \n"[i==N];
}

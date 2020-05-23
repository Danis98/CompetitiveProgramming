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
#define mp std::make_pair
#define pb push_back

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        int N, M, A, B, C;
        std::cin>>N>>M>>A>>B>>C;
        A--;
        B--;
        C--;
        std::vector<ll> p(M);
        for(int i=0;i<M;i++) std::cin>>p[i];
        std::sort(p.begin(), p.end());
        std::vector<std::vector<int>> G(N);
        std::map<ii, ll> w;
        for(int i=0;i<M;i++){
            int a, b;
            std::cin>>a>>b;
            a--;
            b--;
            G[a].pb(b);
            G[b].pb(a);
        }

        std::vector<ll> fromA(N, -1);
        std::queue<int> Qa;
        Qa.push(A);
        fromA[A] = 0;
        while(!Qa.empty()){
            int n = Qa.front();
            Qa.pop();
            for(int neigh : G[n]){
                if(fromA[neigh] == -1){
                    fromA[neigh] = fromA[n] + 1;
                    Qa.push(neigh);
                }
            }
        }

        std::vector<ll> fromB(N, -1);
        std::queue<int> Qb;
        Qb.push(B);
        fromB[B] = 0;
        while(!Qb.empty()){
            int n = Qb.front();
            Qb.pop();
            for(int neigh : G[n]){
                if(fromB[neigh] == -1){
                    fromB[neigh] = fromB[n] + 1;
                    Qb.push(neigh);
                }
            }
        }

        std::vector<ll> fromC(N, -1);
        std::queue<int> Qc;
        Qc.push(C);
        fromC[C] = 0;
        while(!Qc.empty()){
            int n = Qc.front();
            Qc.pop();
            for(int neigh : G[n]){
                if(fromC[neigh] == -1){
                    fromC[neigh] = fromC[n] + 1;
                    Qc.push(neigh);
                }
            }
        }

        std::vector<ll> pre(M);
        pre[0] = p[0];
        for(int i=1;i<M;i++) pre[i] = pre[i-1] + p[i];

        ll best = 2*pre[M-1];
        for(int i=0;i<N;i++){
            int shared = fromB[i];
            int legs = fromA[i] + fromC[i];
            if(shared + legs > M) continue;
            // std::cout<<i<<" "<<shared<<" "<<legs<<"\n";
            if(shared + legs == 0)
                best = 0;
            else if(shared == 0)
                best = std::min(best, pre[legs-1]);
            else{
                best = std::min(best, 2*pre[shared-1] + (pre[legs+shared-1]-pre[shared-1]));
                // std::cout<<i<<" "<<2*pre[shared-1]<<" "<<(pre[legs+shared-1]-pre[shared-1])<<"\n";
            }
            // std::cout<<"["<<i<<" "<<shared<<" "<<legs<<" "<<best<<"]\n";
        }

        std::cout<<best<<"\n";
    }
}

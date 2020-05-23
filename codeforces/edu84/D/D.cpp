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

int N;
std::vector<int> p, c;

std::vector<bool> vis;
std::vector<int> comp, rep;
std::deque<int> L;
void visit(int n){
    if(!vis[n]){
        vis[n] = true;
        visit(p[n]);
        L.push_front(n);
    }
}
void assign(int n, int root){
    if(comp[n] == -1){
        if(rep[root] == -1) rep[root] = n;
        comp[n] = root;
        assign(p[n], root);
    }
}
std::vector<int> comp_sz;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        std::cin>>N;
        p.resize(N);
        c.resize(N);
        vis.assign(N, false);
        comp.assign(N, -1);
        comp_sz.assign(N, 0);
        rep.assign(N, -1);
        for(int i=0;i<N;i++) std::cin>>p[i];
        for(int i=0;i<N;i++) p[i]--;
        for(int i=0;i<N;i++) std::cin>>c[i];

        bool auto_c = false;
        for(int i=0;i<N;i++)
            auto_c |= p[i] == i;
        if(auto_c){
            std::cout<<"1\n";
            continue;
        }

        for(int i=0;i<N;i++) visit(i);
        for(int i=0;i<N;i++)
            assign(L[i], L[i]);
        for(int i=0;i<N;i++) comp_sz[comp[i]]++;

        int res = N;
        for(int i=0;i<N;i++){
            if(comp_sz[i] <= 1) continue;
            int cyc_len = comp_sz[i];
            for(int j=1;j<N;j++){
                int n = rep[i];
                if(cyc_len % j != 0) continue;
                std::vector<int> c_col;
                for(int k=0;k<j;k++){
                    c_col.pb(c[n]);
                    n = p[n];
                }
                bool valid = true;
                for(int k=j;k<cyc_len;k++){
                    if(c_col[k-j] != c[n]){
                        valid = false;
                        break;
                    }
                    n = p[n];
                }
                if(valid){
                    res = std::min(res, j);
                    break;
                }
            }
        }
        std::cout<<res<<"\n";
    }
}

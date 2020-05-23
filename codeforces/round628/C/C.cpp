#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int N;
std::vector<std::vector<int>> tree;
bool placed = false;
int ctr = 0;
std::vector<int> p_num, par;
std::map<ii, int> e_idx;

void place_zero(int n, int p){
    par[n] = p;
    if(tree[n].size() > 2 && !placed){
        placed = true;
        if(n == 0){
            p_num[tree[0][0]] = 0;
            p_num[tree[0][1]] = 1;
            p_num[tree[0][2]] = 2;
        }
        else{
            p_num[n] = 0;
            int ch_placed = 0;
            for(int i=0;i<tree[n].size() || ch_placed < 2;i++){
                if(tree[n][i] == p) continue;
                p_num[tree[n][i]] = ch_placed + 1;
                ch_placed++;
            }
        }
        ctr = 3;
    }
    for(int ch : tree[n])
        if(ch != p)
            place_zero(ch, n);
}

void place_normal(int n, int p){
    if(n != 0 && p_num[n] == -1) p_num[n] = ctr++;
    for(int ch : tree[n])
        if(ch != p)
            place_normal(ch, n);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N;
    tree.resize(N);
    par.resize(N);
    p_num.resize(N, -1);
    for(int i=0;i<N-1;i++){
        int a, b;
        std::cin>>a>>b;
        a--;
        b--;
        tree[a].pb(b);
        tree[b].pb(a);
        e_idx[{a, b}] = i;
        e_idx[{b, a}] = i;
    }

    int root = -1;
    for(int i=0;i<N;i++)
        if(tree[i].size() > 2){
            root = i;
            break;
        }
    if(root == -1){
        for(int i=0;i<N;i++)
            if(tree[i].size() == 1){
                root = i;
                break;
            }
    }

    std::vector<int> res(N-1);
    std::queue<ii> Q;
    Q.push({root, -1});
    while(!Q.empty()){
        ii cur = Q.front();
        Q.pop();
        int n = cur.fi;
        int p = cur.se;
        for(int ch : tree[n])
            if(ch != p){
                res[e_idx[{n, ch}]] = ctr++;
                Q.push({ch, n});
            }
    }

    for(int i=0;i<N-1;i++)
        std::cout<<res[i]<<"\n";
}

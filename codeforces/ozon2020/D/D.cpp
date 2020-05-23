#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int N;
std::vector<std::vector<int>> tree;
std::unordered_set<int> reps;

void del(int n, int p){
    reps.erase(n);
    for(int ch : tree[n])
        if(ch != p && reps.find(ch) != reps.end()) del(ch, n);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    tree.resize(N);
    for(int i=0;i<N-1;i++){
        int a, b;
        std::cin>>a>>b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for(int i=0;i<N;i++) reps.insert(i);
    while(true){
        int a = -1, b = -1, c = -1;
        int m_ctr = -1;
        for(int n : reps){
            int ctr = 0;
            for(int neigh : tree[n])
                if(reps.find(neigh) != reps.end()) ctr++;
            if(ctr > m_ctr){
                b = n;
                m_ctr = ctr;
            }
        }
        if(m_ctr == 0){
            std::cout<<"! "<<(b+1)<<"\n";
            std::cout.flush();
            return 0;
        }
        for(int neigh : tree[b]){
            if(reps.find(neigh) == reps.end()) continue;
            if(a == -1) a = neigh;
            else c = neigh;
        }
        if(c == -1){
            std::cout<<"? "<<(a+1)<<" "<<(b+1)<<"\n";
            std::cout.flush();
            int lca;
            std::cin>>lca;
            if(lca == -1) return 0;
            // std::cout<<"["<<lca<<"]\n";
            lca--;
            if(lca == b)
                del(a, b);
            else del(b, a);
        }
        else{
            std::cout<<"? "<<(a+1)<<" "<<(c+1)<<"\n";
            std::cout.flush();
            int lca;
            std::cin>>lca;
            if(lca == -1) return 0;
            // std::cout<<"["<<lca<<"]\n";
            lca--;
            if(lca == b){
                del(a, b);
                del(c, b);
            }
            else del(b, lca);
        }
        // for(int r : reps)
        //     std::cout<<r+1<<" ";
        // std::cout<<"\n";
    }
}

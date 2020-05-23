#include <bits/stdc++.h>

//Disjoint set
template<typename T>
struct disjoint_set{
    int N;
    int *par, *rank, *sub, num_sets;
    disjoint_set(int N): N(N){
        num_sets=N;
        par=new int[N];
        rank=new int[N];
        sub=new int[N];
        for(int i=0;i<N;i++){
            rank[i]=1;
            sub[i]=1;
            par[i]=i;
        }
    }
    void merge(int a, int b){
        if(a<0 || a>N) return;
        if(b<0 || a>N) return;
        int para=get_par(a), parb=get_par(b);
        if(para==parb) return;
        num_sets--;
        if(rank[para]==rank[parb]) rank[para]++;
        if(rank[para]<rank[parb]) {par[para]=parb; sub[para]+=sub[parb];}
        else {par[parb]=para; sub[parb]+=sub[para];}
    }
    int get_par(int n){
        if(n<0 || n>N) return -1;
        int p=n;
        while(par[p]!=p) p=par[p];
        return par[n]=p;
    }
    bool same_set(int a, int b){
        if(a<0 || a>N) return false;
        if(b<0 || a>N) return false;
        int para=get_par(a), parb=get_par(b);
        return para==parb;
    }
    int set_size(int a){
        return sub[get_par(a)];
    }
};

int N, M;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M;
    disjoint_set<int> grp(N);
    std::set<int> sets[M];
    int k, nulls=0;
    for(int i=0;i<N;i++){
        std::cin>>k;
        if(k==0) nulls++;
        int l;
        for(int j=0;j<k;j++){
            std::cin>>l;
            l--;
            sets[l].insert(i);
        }
    }

    for(int i=0;i<M;i++)
        for(auto it=sets[i].begin();it!=sets[i].end();it++)
            grp.merge(*sets[i].begin(), *it);

    std::cout<<(nulls==N?N:grp.num_sets-1)<<"\n";
}

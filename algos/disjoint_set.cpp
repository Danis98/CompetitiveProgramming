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
        if(rank[ra] > rank[rb]) p[rb] = ra;
        else{
            p[ra] = rb;
            if(rank[ra] == rank[rb]) rank[rb]++;
        }
    }
};

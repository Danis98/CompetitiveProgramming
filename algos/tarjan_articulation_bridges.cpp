std::vector<int> dfs_num, dfs_low;
std::vector<bool> art_vertex;
int tarjan_ctr = 0, root_ch = 0, root;

void tarjan_articulation_bridges(int n, int p){
    dfs_low[n] = dfs_num[n] = ctr++;
    for(int neigh : G[n]){
        if(dfs_num[neigh] == -1){
            if(n == root) root_ch++;
            tarjan_articulation_bridges(neigh, n);
            if(dfs_low[neigh] >= dfs_num[n])
                art_vertex[n] = true;
            if(dfs_low[neigh] > dfs_num[n])
                std::cout<<"Bridge "<<n<<" "<<neigh<<"\n";
            dfs_low[n] = std::min(dfs_low[n], dfs_low[neigh]);
        }
        else if(neigh != p) dfs_low[n] = std::min(dfs_low[n], dfs_num[neigh]);
    }
}

// in main
for(int i=0;i<N;i++)
    if(dfs_num[i] == -1){
        root = i;
        root_ch = 0;
        tarjan_articulation_bridges(root, -1);
        art_vertex[root] = root_ch > 1;
    }

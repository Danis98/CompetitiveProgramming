
int N, M;
std::vector<std::vector<int>> G;
std::vector<int> comp, comp_size, vis;
std::deque<int> L;

void visit(int n){
    if(!vis[n]){
        vis[n] = 1;
        for(int neigh : G[n])
            visit(neigh);
        L.pf(n);
    }
}

void assign(int n, int root){
    if(comp[n] != -1){
        comp[n] = root;
        for(int neigh : G[n])
            assign(neigh, root);
    }
}

int main(){
    for(int i=0;i<N;i++) visit(i);
    for(int i=0;i<N;i++) assign(L[i], L[i]);
    for(int i=0;i<N;i++) comp_size[comp[i]]++;
}

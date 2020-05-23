#include <bits/stdc++.h>

typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;

int N, M, S;
std::vector<std::vector<int>> Gd;
std::vector<std::vector<ii>> Gu;
std::map<iii, int> undir;
bool vis[300000];
int vis_max=0, vis_min=0;

void dfs_max(int n, int p){
    vis[n]=true;
    vis_max++;
    for(auto it=Gu[n].begin();it!=Gu[n].end();it++){
        if(vis[it->first] || it->first==p) continue;
        if(undir.find({it->second, {n, it->first}})!=undir.end())
            undir[{it->second, {n, it->first}}]=1;
        else if(undir.find({it->second, {it->first, n}})!=undir.end())
            undir[{it->second, {it->first, n}}]=-1;
        else continue;
        dfs_max(it->first, n);
    }
    for(auto it=Gd[n].begin();it!=Gd[n].end();it++){
        if(vis[*it] || *it==p) continue;
        dfs_max(*it, n);
    }
}

void dfs_min(int n, int p){
    vis[n]=true;
    vis_min++;
    for(auto it=Gu[n].begin();it!=Gu[n].end();it++){
        if(vis[it->first] || it->first==p) continue;
        if(undir.find({it->second, {n, it->first}})!=undir.end())
            undir[{it->second, {n, it->first}}]=-1;
        else if(undir.find({it->second, {it->first, n}})!=undir.end())
            undir[{it->second, {it->first, n}}]=1;
        else continue;
    }
    for(auto it=Gd[n].begin();it!=Gd[n].end();it++){
        if(vis[*it] || *it==p) continue;
        dfs_min(*it, n);
    }
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M>>S;
    S--;
    Gd.resize(N);
    Gu.resize(N);
    int ind=0;
    for(int i=0;i<M;i++){
        int t, a, b;
        std::cin>>t>>a>>b;
        a--;
        b--;
        if(t==1)
            Gd[a].push_back(b);
        if(t==2){
            Gu[a].push_back({b, ind});
            Gu[b].push_back({a, ind});
            undir[{ind++, {a, b}}]=0;
        }
    }

    for(int i=0;i<N;i++) vis[i]=false;
    dfs_max(S, -1);
    std::cout<<vis_max<<"\n";
    for(auto it=undir.begin();it!=undir.end();it++){
        std::cout<<(it->second==1?"+":"-");
        it->second=0;
    }
    std::cout<<"\n";
    for(int i=0;i<N;i++) vis[i]=false;
    dfs_min(S, -1);
    std::cout<<vis_min<<"\n";
    for(auto it=undir.begin();it!=undir.end();it++)
        std::cout<<(it->second==1?"+":"-");
    std::cout<<"\n";
}

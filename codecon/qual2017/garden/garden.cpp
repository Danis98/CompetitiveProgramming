#include <bits/stdc++.h>

typedef std::pair<int, int> ii;

int N;
int H, W;
ii coord[128];
int rad[128];
bool vis[128+2];

std::vector<std::vector<int>> G(128+2);

int dist(int a, int b){
    return (coord[a].first-coord[b].first)*(coord[a].first-coord[b].first)+
            (coord[a].second-coord[b].second)*(coord[a].second-coord[b].second);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>H>>W>>N;
    int x, y, r;
    for(int i=0;i<N;i++)
        std::cin>>coord[i].first>>coord[i].second>>rad[i];

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int dd=dist(i, j);
            if(dd<(rad[i]+rad[j])*(rad[i]+rad[j])){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }

    for(int i=0;i<130;i++) vis[i]=false;

    for(int i=0;i<N;i++){
        if(coord[i].second-rad[i]<0){
            G[128].push_back(i);
            G[i].push_back(128);
        }
        if(coord[i].second+rad[i]>H){
            G[129].push_back(i);
            G[i].push_back(129);
        }
    }

    std::queue<int> Q;
    Q.push(128);
    vis[128]=true;
    while(!Q.empty()){
        int n=Q.front();
        Q.pop();
        for(auto it=G[n].begin();it!=G[n].end();it++){
            if(vis[*it]) continue;
            vis[*it]=true;
            Q.push(*it);
        }
    }

    if(vis[129]) std::cout<<"NO CAKE\n";
    else std::cout<<"CAKE\n";
}

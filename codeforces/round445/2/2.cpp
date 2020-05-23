#include <bits/stdc++.h>

int N;
std::map<int, int> vis;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    for(int i=0;i<N;i++){
        int ind;
        std::cin>>ind;
        vis[ind]=i;
    }

    int min=1000000000;
    for(auto it=vis.begin();it!=vis.end();it++)
        if(min==1000000000 || it->second<vis[min])
            min=it->first;

    std::cout<<min<<"\n";
}

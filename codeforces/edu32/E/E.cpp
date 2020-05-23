#include <bits/stdc++.h>

int N, M;
int a[25];
int res=0;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M;
    for(int i=0;i<N;i++){
        std::cin>>a[i];
        a[i]%=M;
        res=std::max(res, a[i]);
    }

    std::set<int> reach;
    std::vector<int> ins;
    reach.clear();
    reach.insert(0);
    for(int i=0;i<N;i++){
        for(auto it=reach.begin();it!=reach.end();it++){
            int v=(*it+a[i])%M;
            res=std::max(v, res);
            ins.push_back(v);
        }
        for(auto it=ins.begin();it!=ins.end();it++)
            reach.insert(*it);
        ins.clear();
    }

    std::cout<<res<<"\n";
}

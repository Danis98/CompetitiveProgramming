#include <bits/stdc++.h>

typedef long long int ll;
typedef std::pair<int, int> ii;

int N;
std::map<std::string, std::vector<std::string>> G;
std::map<std::string, int> knights;
std::map<std::string, std::string> par;
std::string root;

std::map<int, std::vector<std::string>> res;

void dfs(std::string house, int d){
    res[d].push_back(house);
    for(auto it=G[house].begin();it!=G[house].end();it++){
        dfs(*it, d+1);
    }
}

std::string war(std::string house, int d){
    if(G[house].size()==0) return house;
    int K=knights[house];
    std::string maxch="";
    for(auto it=G[house].begin();it!=G[house].end();it++){
        std::string ch=war(*it, d+1);
        if(maxch==""
        || knights[ch]>knights[maxch]
        || knights[ch]==knights[maxch] && ch<maxch)
            maxch=ch;
    }
    if(K>knights[maxch]-3) return house;
    std::vector<std::string> sub=G[maxch];
    G[house].erase(std::find(G[house].begin(), G[house].end(), maxch));
    G[house].push_back(house);
    G[maxch]=G[house];
    G[house]=sub;
    std::string p=par[house];
    if(p!="")
        *std::find(G[p].begin(), G[p].end(), house)=maxch;
    return maxch;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    std::string name, child;
    int k, num_ch;
    for(int i=0;i<N;i++){
        std::cin>>name>>k>>num_ch;
        knights[name]=k;
        for(int j=0;j<num_ch;j++){
            std::cin>>child;
            G[name].push_back(child);
            par[child]=name;
        }
    }

    root=name;
    while(par[root]!="") root=par[root];

    root=war(root, 0);

    dfs(root, 0);
    for(auto it=res.begin();it!=res.end();it++){
        std::sort(it->second.begin(), it->second.end());
        for(auto itt=it->second.begin();itt!=it->second.end();itt++)
            std::cout<<*itt<<" ";
        std::cout<<"\n";
    }
}

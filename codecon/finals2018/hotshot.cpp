#include <bits/stdc++.h>

typedef std::pair<int, int> ii;
typedef std::pair<ii, int> iii;

int L;
std::map<int, int> line;

ii atk[5], def[5];

int main(){
    std::cin>>L;
    int x, y;
    for(int i=0;i<L;i++){
        std::cin>>x>>y;
        line[x]=std::max(line[x], y);
    }
    for(int i=0;i<5;i++)
        std::cin>>atk[i].first>>atk[i].second;
    for(int i=0;i<5;i++)
        std::cin>>def[i].first>>def[i].second;
    int ballx, bally;
    std::cin>>ballx>>bally;

    std::vector<iii> v1;
    std::vector<ii> v2;
    for(int i=0;i<5;i++){
        x=atk[i].first;
        y=atk[i].second;
        if(line[x]>=y) continue;
        int defd=10000000;
        for(int i=0;i<5;i++)
            defd=std::min(defd, (x-def[i].first)*(x-def[i].first)+(y-def[i].second)*(y-def[i].second));
        int balld=(x-ballx)*(x-ballx)+(y-bally)*(y-bally);
        v1.push_back({{defd, balld}, i});
    }
    std::sort(v1.begin(), v1.end(), [](iii a, iii b){
        if(a.first.first==b.first.first)
            return a.first.second<b.first.second;
        return a.first.first>b.first.first;
    });
    if(v1.size()==0){
        std::cout<<"-1 -1\n";
        return 0;
    }
    v2.push_back(atk[v1[0].second]);
    for(int i=1;i<v1.size();i++){
        if(v1[i].first!=v1[0].first) break;
        v2.push_back(atk[v1[i].second]);
    }
    std::sort(v2.begin(), v2.end());
    for(int i=0;i<v2.size();i++)
        std::cout<<v2[i].first<<" "<<v2[i].second<<" ";
    std::cout<<"\n";
}

#include <bits/stdc++.h>

typedef std::pair<int, int> ii;

ii p[3];

int main(){
    std::cin>>p[0].first>>p[0].second>>p[1].first>>p[1].second>>p[2].first>>p[2].second;
    std::sort(p, p+3);
    //straight line
    if(p[0].first==p[1].first && p[1].first==p[2].first || p[0].second==p[1].second && p[1].second==p[2].second)
        std::cout<<"1\n";
    //2 lines
    else if(p[0].first==p[1].first && (p[2].second>=p[1].second || p[2].second<=p[0].second)
    || p[0].second==p[1].second
    || p[1].first==p[2].first && (p[0].second<=p[1].second || p[0].second>=p[2].second)
    || p[1].second==p[2].second)
        std::cout<<"2\n";
    else
        std::cout<<"3\n";
}

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::map<std::string, int> id;
    std::map<int, bool> present;
    int ctr = 0, present_ctr = 0;

    std::string title, name, the, nick;
    std::cin>>title;
    while(title != "----------"){
        std::cin>>name>>the>>nick;
        id[title+" "+name] = ctr;
        id[the+" "+nick] = ctr++;
        std::cin>>title;
    }
    std::string cmd, a, b;
    std::cin>>cmd;
    while(cmd != "END"){
        if(cmd == "+"){
            std::cin>>a>>b;
            present[id[a+" "+b]] = true;
            present_ctr++;
        }
        else if(cmd == "-"){
            std::cin>>a>>b;
            present[id[a+" "+b]] = false;
            present_ctr--;
        }
        else if(cmd == "UNION"){
            std::cout<<present_ctr<<"\n";
        }
        else if(cmd == "FIND"){
            std::cin>>a>>b;
            if(present[id[a+" "+b]]) std::cout<<"FOUND\n";
            else std::cout<<"404\n";
        }
        std::cin>>cmd;
    }
}

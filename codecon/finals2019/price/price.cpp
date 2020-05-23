//Problem        : Price query
//Language       : C++14
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>

int C, N;

std::vector<std::vector<std::string>> table;
std::vector<int> prices;
std::vector<int> priority;

int main() {
    std::cin>>C;
    std::string cats;
    for(int i=0;i<C;i++) std::cin>>cats;
    std::cin>>N;
    table.resize(N);
    priority.resize(N);
    prices.resize(N);
    for(int i=0;i<N;i++){
        priority[i] = 0;
        table[i].resize(C);
        for(int j=0;j<C;j++) std::cin>>table[i][j];
        std::cin>>prices[i];
    }

    std::vector<std::string> spec(C);
    for(int i=0;i<C;i++) std::cin>>spec[i];

    std::vector<int> matches;
    for(int i=0;i<N;i++){
        bool m = true;
        for(int j=0;j<C;j++){
            if(table[i][j]!="*" && table[i][j]!=spec[j]) m=false;
        }
        if(m) matches.push_back(i);
    }

    if(matches.size()==0){
        std::cout<<"NotFound\n";
        return 0;
    }

    /*std::cout<<matches.size()<<"\n";
    for(int i=0;i<matches.size();i++) std::cout<<matches[i]<<"\n";*/

    std::sort(matches.begin(),matches.end(),[table,C](int a, int b){
        for(int i=0;i<C;i++){
            if(table[a][i]==table[b][i]) continue;
            if(table[a][i]=="*") return false;
            else return true;
        }
    });

    std::cout<<prices[matches[0]]<<"\n";

    return 0;
}

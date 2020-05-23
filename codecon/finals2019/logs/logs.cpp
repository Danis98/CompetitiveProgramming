//Problem        : Lost in the Logs
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
#include <map>
#include <utility>
#include <set>

typedef std::pair<int, int> ii;
typedef std::pair<std::string, std::string> ss;
typedef std::pair<ii, std::string> iis;
typedef std::pair<int, ss> iss;

int T, P, N;
std::map<std::string, int> problem_scores;

std::map<std::string, ii> user_scores;
std::map<std::string, iss> pending_subs;
std::set<ss> acc;

int main() {
    std::cin>>T>>P;
    for(int i=0;i<P;i++){
        std::string name;
        int score;
        std::cin>>score>>name;
        problem_scores[name]=score;
    }
    problem_scores[""]=0;

    std::cin>>N;
    for(int i=0;i<N;i++){
        int t;
        std::string type, hash;
        std::cin>>t>>type>>hash;
        if(type=="SUBMIT"){
            std::string uname, pname;
            std::cin>>uname>>pname;
            if(t>T) pname="";
            pending_subs[hash] = {i, {uname, pname}};
        }
        else if(type=="ACCEPT"){
            iss sub = pending_subs[hash];
            int sub_time = sub.first;
            ss data = sub.second;
            if(acc.find(data)==acc.end()){
                std::string uname=data.first, pname=data.second;
                user_scores[uname]={user_scores[uname].first+problem_scores[pname], sub_time};
                acc.insert(data);
            }
        }
    }

    std::vector<iis> scores;
    for(auto it=user_scores.begin();it!=user_scores.end();it++)
        scores.push_back({it->second, it->first});
    std::sort(scores.begin(),scores.end(), [](iis a, iis b){
        if(a.first.first==b.first.first)
            return a.first.second < b.first.second;
        return a.first.first > b.first.first;
    });

    for(int i=0;i<scores.size();i++)
        std::cout<<scores[i].first.first<<" "<<scores[i].second<<"\n";

    return 0;
}

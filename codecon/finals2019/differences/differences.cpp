//Problem        : Spot Two Differences
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

int A, N, B;
std::string alph;
std::vector<std::string> strs;

int main() {
    std::cin>>A>>alph>>N>>B;
    for(int i=0;i<N;i++){
        std::string temp;
        std::cin>>temp;
        strs.push_back(temp);
    }

    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int diff=0;
            for(int k=0;k<B;k++)
                if(strs[i][k]!=strs[j][k]) diff++;
            if(diff==2) cnt++;
        }
    }
    std::cout<<cnt;
    return 0;
}

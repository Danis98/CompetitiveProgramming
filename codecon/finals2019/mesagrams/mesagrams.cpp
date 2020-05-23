//Problem        : Messy Mesagrams
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

int N, K;

std::vector<int> freq;

int main() {
    std::cin>>N>>K;
    freq.resize(N);
    for(int i=0;i<N;i++){
        std::string S;
        std::cin>>S;
        freq[i]=0;
        for(int j=0;j<S.size();j++)
            freq[i]|= 1<<(S[j]-'a');
    }
    int cnt=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(i!=j && freq[i]==freq[j]){cnt++;break;}
    std::cout<<cnt;
    return 0;
}

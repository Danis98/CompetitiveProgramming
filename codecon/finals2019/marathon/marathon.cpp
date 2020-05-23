//Problem        : Marathon
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

int N, K, X;
std::vector<std::vector<int>> times;

int get_score(int n, int t){
    int sc=0;
    for(int i=0;i<K;i++)
        if(times[n][i]<t && times[n][i]>=0) sc++;
    return sc;
}

int main() {
    std::cin>>N>>K>>X;
    int maxt=0;
    times.resize(N);
    for(int i=0;i<N;i++){
        times[i].resize(K);
        for(int j=0;j<K;j++){
            std::cin>>times[i][j];
            maxt=std::max(maxt, times[i][j]);
        }
    }

    int LIMT = 1000000000;
    int a=0, b=LIMT;
    while(a<b){
        //std::cout<<a<<" "<<b<<"\n";
        int t=(a+b)/2;
        int cnt=0;
        int my_score;
        for(int i=0;i<N;i++){
            int score=get_score(i, t);
            if(i==0) my_score=score;
            if(i>0 && score > my_score) cnt++;
        }
        //std::cout<<cnt<<"\n";
        if(cnt>=X || my_score <= 0) a=t+1;
        else b=t;
    }
    if(a==b && a > 0 && b < LIMT && get_score(0, a)>0) std::cout<<a<<"\n";
    else std::cout<<"IMPOSSIBLE\n";
    return 0;
}

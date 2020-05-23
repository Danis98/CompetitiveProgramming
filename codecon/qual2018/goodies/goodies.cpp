//Problem        : Tracing Vile Angus
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <utility>
#include <queue>

using namespace std;

#define MAXN 12

int N, K, D;
int G[MAXN];

bool taken[MAXN];
int taken_count=0;

int dfs(int n){
    //cout<<n<<" "<<taken_count<<"\n";
    if(n+D >= N)return taken_count;
    int res=0;
    for(int j=n+D;j<N;j+=D){
        bool n=!taken[G[j]];
        if(n){
            taken[G[j]]=true;
            taken_count++;
        }
        res=max(res, dfs(j));
        if(n){
            taken_count--;
            taken[G[j]]=false;
        }
    }
    return res;
}

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    cin>>N>>K>>D;
    for(int i=0;i<N;i++) cin>>G[i];

    int res=0;
    for(int i=0;i<N;i++){
        taken_count = 1;
        taken[G[i]]=true;
        res=max(res, dfs(i));
        taken[G[i]]=false;
    }

    cout<<res<<"\n";

    return 0;
}

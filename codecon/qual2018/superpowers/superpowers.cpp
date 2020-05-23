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
#include <map>

using namespace std;

#define MAXN 12

typedef pair<int, int> ii;

int N;
queue<ii> Q;
map<int, bool> vis;

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    cin>>N;
    Q.push({N, 0});

    while(!Q.empty()){
        int strength = Q.front().first;
        int dist = Q.front().second;
        Q.pop();
        vis[strength] = true;
        //cout<<strength<<" "<<dist<<"\n";
        if(strength==1){
            cout<<dist<<"\n";
            break;
        }
        //if(dist>5) break;
        if(strength%3==0 && !vis[strength/3]) Q.push({strength/3, dist+1});
        if(strength%2==0 && !vis[strength/2]) Q.push({strength/2, dist+1});
        if(!vis[strength-1]) Q.push({strength-1, dist+1});
    }

    return 0;
}

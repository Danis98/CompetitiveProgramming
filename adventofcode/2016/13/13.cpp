#include <bits/stdc++.h>

typedef std::pair<int, int> ii;

int seed=1362;

ii start={1, 1}, end={31, 39};
std::map<ii, int> dist;

bool square(int x, int y){
    int n=x*x+3*x+2*x*y+y+y*y+seed;
    int cnt=0;
    while(n){
        if(n%2) cnt++;
        n>>=1;
    }
    return cnt%2;
}

int main(){
    std::queue<ii> Q;
    Q.push(start);
    dist[start]=0;
    while(!Q.empty()){
        ii n=Q.front();
        Q.pop();
        if(dist[n]==50) continue;
        //if(n==end) break;
        if(n.first>0
        && !square(n.first-1, n.second)
        && dist.find({n.first-1, n.second})==dist.end()){
            dist[{n.first-1, n.second}]=dist[n]+1;
            Q.push({n.first-1, n.second});
        }
        if(n.second>0
        && !square(n.first, n.second-1)
        && dist.find({n.first, n.second-1})==dist.end()){
            dist[{n.first, n.second-1}]=dist[n]+1;
            Q.push({n.first, n.second-1});
        }
        if(!square(n.first+1, n.second)
        && dist.find({n.first+1, n.second})==dist.end()){
            dist[{n.first+1, n.second}]=dist[n]+1;
            Q.push({n.first+1, n.second});
        }
        if(!square(n.first, n.second+1)
        && dist.find({n.first, n.second+1})==dist.end()){
            dist[{n.first, n.second+1}]=dist[n]+1;
            Q.push({n.first, n.second+1});
        }
    }

    std::cout<<dist.size()<<"\n";
}

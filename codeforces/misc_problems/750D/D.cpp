#include <bits/stdc++.h>

#define N   0
#define NW  1
#define W   2
#define SW  3
#define S   4
#define SE  5
#define E   6
#define NE  7

typedef std::pair<int, int> ii;

ii advance(ii pos, int dir){
    switch(dir){
        case N:
            return {pos.first+1, pos.second};
        case NW:
            return {pos.first+1, pos.second+1};
        case W:
            return {pos.first, pos.second+1};
        case SW:
            return {pos.first-1, pos.second+1};
        case S:
            return {pos.first-1, pos.second};
        case SE:
            return {pos.first-1, pos.second-1};
        case E:
            return {pos.first, pos.second-1};
        case NE:
            return {pos.first+1, pos.second-1};
    }
}

ii get_next(int dir){
    switch(dir){
        case N:
            return {NE, NW};
        case NW:
            return {N, W};
        case W:
            return {NW, SW};
        case SW:
            return {W, S};
        case S:
            return {SE, SW};
        case SE:
            return {E, S};
        case E:
            return {SE, NE};
        case NE:
            return {E, N};
    }
}

int n;
int t[30];

std::map<ii, bool> cells;
std::map<std::pair<ii, ii>, bool> q;

void firework(ii pos, int rec, int dir){
    if(q[{pos, {rec, dir}}]) return;
    q[{pos, {rec, dir}}]=true;
    if(rec==n) return;
    for(int i=0;i<t[rec];i++){
        pos=advance(pos, dir);
        cells[pos]=true;
    }
    ii next=get_next(dir);
    firework(pos, rec+1, next.first);
    firework(pos, rec+1, next.second);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>n;
    for(int i=0;i<n;i++) std::cin>>t[i];

    firework({-1, 0}, 0, N);

    std::cout<<cells.size()<<"\n";
}

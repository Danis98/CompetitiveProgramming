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

#define MAXN 1001
#define MAXM 1000001

int N, M;
int G[MAXM];
int proc[MAXN];

typedef pair<int, int> ii;

priority_queue<ii, std::vector<ii>, std::greater<ii>> Q;

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    cin>>N>>M;

    for(int i=0;i<N;i++) Q.push({0, i});
    for(int i=0;i<N;i++) proc[i]=0;

    for(int i=0;i<M;i++){
        int delta;
        cin>>delta;
        int mint = Q.top().first;
        int booth = Q.top().second;
        //cout<<mint<<" "<<booth<<" "<<delta<<"\n";
        Q.pop();
        int fint = mint+delta;
        proc[booth]++;
        if(proc[booth]!=0 && proc[booth]%10==0) fint += 5;
        Q.push({fint, booth});
    }

    for(int i=0;i<N;i++) cout<<proc[i]<<" ";
    cout<<"\n";

    return 0;
}

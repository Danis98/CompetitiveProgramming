#include <bits/stdc++.h>

int N, B, E, S;
std::map<int, int> bath;
std::map<int, int> elev;

typedef std::pair<int, int> ii;

int dist[30];

int main(){
    std::cin>>N;
    std::cin>>B;
    int t;
    for(int i=0;i<B;i++){
        std::cin>>t;
        bath[t]=1;
    }
    std::cin>>E;
    for(int i=0;i<E;i++){
        std::cin>>t;
        elev[t]=1;
    }
    std::cin>>S;
    for(int i=0;i<N;i++) dist[i]=1000;
    dist[S]=0;

    std::priority_queue<ii, std::vector<ii>, std::greater<ii>> Q;
    Q.push({0, S});
    while(!Q.empty()){
        int n=Q.top().second;
        Q.pop();
        if(bath[n]==1){
            std::cout<<dist[n]<<"\n";
            break;
        }
        for(int i=0;i<N;i++){
            if(i==n) continue;
            // stairs
            if(i<n){
                if(dist[n]+10*(n-i)<dist[i]){
                    dist[i]=dist[n]+10*(n-i);
                    Q.push({dist[i], i});
                }
                if(elev[n]==1 && elev[i]==1){
                    if(dist[n]+5*(n-i)+15<dist[i]){
                        dist[i]=dist[n]+5*(n-i)+15;
                        Q.push({dist[i], i});
                    }
                }
            }
            else{
                if(dist[n]+20*(i-n)<dist[i]){
                    dist[i]=dist[n]+20*(i-n);
                    Q.push({dist[i], i});
                }
                if(elev[n]==1 && elev[i]==1){
                    if(dist[n]+5*(i-n)+15<dist[i]){
                        dist[i]=dist[n]+5*(i-n)+15;
                        Q.push({dist[i], i});
                    }
                }
            }
        }
    }
    return 0;
}

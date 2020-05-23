#include <iostream>
#include <algorithm>

#define MAXN 100001
#define MAXA 1000000000

int N, M;
int A[MAXN], P[MAXN], G[MAXN];
int E[MAXN];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M;
    for(int i=0;i<M;i++) std::cin>>E[i];
    for(int i=0;i<N;i++) std::cin>>A[i]>>P[i]>>G[i];

    int catN=0, dogN=0;
    int catMax=-1, dogMax=-1;
    int catMin=MAXA+1, dogMin=MAXA+1;

    for(int i=0;i<N;i++){
        if(P[i]==0){
            dogN++;
            dogMax=std::max(dogMax, A[i]);
            dogMin=std::min(dogMin, A[i]);
        }
        if(P[i]==1){
            catN++;
            catMax=std::max(catMax, A[i]);
            catMin=std::min(catMin, A[i]);
        }
    }

    for(int i=0;i<M;i++){
        if(E[i]==0){

        }
    }
}

#include <bits/stdc++.h>

int mem[101][101];

int N;
int A[100];

bool part(int n, int d){
    if(mem[n][d]!=-1) return mem[n][d];
    if(n>=N){
        mem[n][d]=(d%2==1);
        return d%2==1;
    }
    if(A[n]%2==0){ mem[n][d]=0; return false;}
    for(int i=n;i<N;i+=2)
        if(A[i]%2==1 && part(i+1, d+1)){
            mem[n][d]=1;
            return true;
        }
    mem[n][d]=0;
    return false;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    for(int i=0;i<N;i++) std::cin>>A[i];

    for(int i=0;i<101;i++)
        for(int j=0;j<101;j++)
            mem[i][j]=-1;

    if(part(0, 0)) std::cout<<"Yes\n";
    else std::cout<<"No\n";
}

#include <bits/stdc++.h>

#define MOD 10007

typedef unsigned long long int ull;
typedef std::pair<int, int> ii;
typedef std::pair<ii, int> iii;

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int N, K, L;
int *V;

std::map<iii, ull> mem;

int dp(int n, int p, int s){
    if(s>=L || n>N-1) return 0;
    if(p>=K) return 1;
    if(mem.find({{n, p}, s})!=mem.end()) return mem[{{n, p}, s}];
    ull count=0;
    for(int i=n;i<N;i++)
        count=(count+dp(i+1, p+1, s+V[i]))%MOD;
    mem[{{n, p}, s}]=count;
    return count;
}

int main(){
    fin>>L>>N>>K;
    V=new int[N];
    for(int i=0;i<N;i++) fin>>V[i];

    std::sort(V, V+N, [](int a, int b){return a>b;});
    ull un=dp(0, 0, 0);
    ull kfact1=1;
    for(int i=2;i<=K;i++) kfact1=(kfact1*i)%MOD;
    ull kfact2=1;
    for(int i=2;i<=N-K-1;i++) kfact2=(kfact2*i)%MOD;
    ull nfact=1;
    for(int i=2;i<N;i++) nfact=(nfact*i)%MOD;
    ull res=(nfact-(un*kfact1*kfact2)%MOD+MOD)%MOD;
    fout<<res<<"\n";
}

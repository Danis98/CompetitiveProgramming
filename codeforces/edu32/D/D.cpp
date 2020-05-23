#include <bits/stdc++.h>

typedef unsigned long long int ull;

int N, K;

int d[5]={0, 0, 2, 6, 24};
int f[5]={0, 0, 1, 2, 9};

ull rec(int n, int k){
    if(k<=1) return 1;
    ull fact=1;
    for(int i=0;i<k;i++) fact*=n-i;
    fact/=d[k];
    fact*=f[k];
    return fact+rec(n, k-1);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>K;
    std::cout<<rec(N, K)<<"\n";
}

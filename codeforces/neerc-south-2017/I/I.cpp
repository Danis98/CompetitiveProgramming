#include <bits/stdc++.h>

typedef unsigned long long int ull;

int N, K;
ull v[300000];

bool check(int diff){
    std::cout<<"CHECKING D="<<diff<<"\n";
    int beg=0;
    int rem=N/K-1;
    for(int i=0;i<N;i++){
        std::cout<<(N-i-1)<<" "<<(K*rem)<<"\n";
        if(v[i]-v[beg]>diff || N-i-1==K*rem){
            int len=i-beg+1;
            if(len<K || rem<0) return false;
            beg=i;
            rem--;
        }
    }
    return true;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>K;
    for(int i=0;i<N;i++) std::cin>>v[i];
    std::sort(v, v+N);
    int a=0, b=1000000000;
    while(a<b){
        int m=(a+b)/2;
        if(check(m)) b=m;
        else a=m+1;
    }

    std::cout<<a<<"\n";
}

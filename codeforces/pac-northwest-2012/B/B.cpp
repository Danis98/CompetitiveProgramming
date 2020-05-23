#include <iostream>

typedef unsigned long long int ull;

bool dig[10];
int remain;

void check(ull N){
    while(N>0){
        int d = N % 10;
        N /= 10;
        if(dig[d]) continue;
        remain--;
        dig[d] = true;
    }
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ull N, k=1;
    while(std::cin>>N){
        for(int i=0;i<10;i++) dig[i]=false;
        remain=10;
        k=1;
        while(remain>0){
            check(k*N);
            if(remain>0) k++;
        }
        std::cout<<k<<"\n";
    }
}

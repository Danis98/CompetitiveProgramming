#include <bits/stdc++.h>

int N, T=0;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    for(int i=0;i<N;i++){
        int s, d;
        std::cin>>s>>d;
        if(i==0) T=s;
        else
            for(int j=0;j<100000;j++)
                if(s+j*d>T) {T=s+j*d; break;}
    }
std::cout<<T<<"\n";
}

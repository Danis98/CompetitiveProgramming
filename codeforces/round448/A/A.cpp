#include <bits/stdc++.h>

int N, a[360];
int pre[360];
int S=0;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    for(int i=0;i<N;i++){
        std::cin>>a[i];
        pre[i]=a[i]+(i>0?pre[i-1]:0);
        S+=a[i];
    }

    int res=1000000000;
    for(int i=0;i<N;i++)
        for(int j=i;j<N;j++)
            res=std::min(res, abs((pre[j]-(i==0?0:pre[i-1]))*2-S));
    std::cout<<res<<"\n";
}

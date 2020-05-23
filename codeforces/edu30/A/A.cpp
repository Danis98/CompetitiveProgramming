#include <bits/stdc++.h>

int N, K, X;
int a[100];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>K>>X;
    for(int i=0;i<N;i++) std::cin>>a[i];

    int tot=0;
    for(int i=N-1;i>=0;i--){
        if(a[i]>X && K>0){
            tot+=X;
            K--;
        }
        else tot+=a[i];
    }

    std::cout<<tot<<"\n";
}

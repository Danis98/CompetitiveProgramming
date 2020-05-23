#include <bits/stdc++.h>

int N;
int a[1000];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    for(int i=0;i<N;i++) std::cin>>a[i];

    int cnt=0;
    for(int i=1;i<N-1;i++)
        if(a[i-1]<a[i] && a[i]>a[i+1] || a[i-1]>a[i] && a[i]<a[i+1])
            cnt++;
    std::cout<<cnt<<"\n";
}

#include <bits/stdc++.h>

int N, cnt=2;
char last;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    std::cin>>last;
    for(int i=1;i<N;i++){
        char ch;
        std::cin>>ch;
        if(ch!=last) cnt++;
        last=ch;
    }

    std::cout<<cnt<<"\n";
}

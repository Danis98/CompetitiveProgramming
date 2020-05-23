#include <bits/stdc++.h>

int N;
int ud=0, lr=0;
int fx=0, fy=0;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    for(int i=0;i<N;i++){
        char cmd;
        std::cin>>cmd;
        if(cmd=='U'){
            ud++;
            fy++;
        }
        else if(cmd=='D'){
            ud++;
            fy--;
        }
        else if(cmd=='L'){
            lr++;
            fx--;
        }
        else if(cmd=='R'){
            lr++;
            fx++;
        }
    }

    std::cout<<(ud-abs(fy)+lr-abs(fx))<<"\n";
}

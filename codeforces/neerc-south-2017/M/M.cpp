#include <bits/stdc++.h>

int X0, Y0, X1, Y1;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>X0>>Y0>>X1>>Y1;
    int dx=abs(X0-X1)+1;
    int dy=abs(Y0-Y1)+1;
    dx=std::max(2, dx);
    dy=std::max(2, dy);
    std::cout<<(2*(dx+dy))<<"\n";
}

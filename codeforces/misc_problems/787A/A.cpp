#include <bits/stdc++.h>

int a, b, c, d;

int main(){
    std::cin>>a>>b>>c>>d;
    int i=0;
    for(i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++)
            if(a*i+b==c*j+d){
                std::cout<<(a*i+b)<<"\n";
                return 0;
            }
    }

    std::cout<<"-1\n";
}

#include <iostream>

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N;
    std::cin>>N;
    for(int i=0;i<N;i++){
        int w1, w2, v1, v2, v3, v4, v5, v6, v7;
        std::cin>>v1>>v2>>v3>>v4>>v5>>v6;
        w1 = v1 + 2*v2 + 3*v3 + 3*v4 + 4*v5 + 10*v6;
        std::cin>>v1>>v2>>v3>>v4>>v5>>v6>>v7;
        w2 = v1 + 2*v2 + 2*v3 + 2*v4 + 3*v5 + 5*v6 + 11*v7;

        std::cout<<"Battle "<<(i+1)<<": ";
        if(w1 > w2)
            std::cout<<"Good triumphs over Evil\n";
        else if(w1 < w2)
            std::cout<<"Evil eradicates all trace of Good\n";
        else if(w1 == w2)
            std::cout<<"No victor on this battle field\n";
    }
}

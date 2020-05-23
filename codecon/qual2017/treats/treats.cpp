#include <bits/stdc++.h>

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::string enc, dec, temp;
    do{
        std::cin>>enc>>temp>>temp>>temp>>temp>>dec;
        std::cout<<(enc[0]-dec[0]+26)%26<<"\n";
    }while(std::cin.eof());
}

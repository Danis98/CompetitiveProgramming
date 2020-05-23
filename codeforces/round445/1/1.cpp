#include <bits/stdc++.h>

int a[6];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int s=0;
    for(int i=0;i<6;i++){
        std::cin>>a[i];
        s+=a[i];
    }

    if(s%2==1){
        std::cout<<"NO\n";
        return 0;
    }

    for(int i=0;i<6;i++)
        for(int j=i+1;j<6;j++)
            for(int k=j+1;k<6;k++)
                if(a[i]+a[j]+a[k]==s/2){
                    std::cout<<"YES\n";
                    return 0;
                }
    std::cout<<"NO\n";
    return 0;
}

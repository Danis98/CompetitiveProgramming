#include <bits/stdc++.h>

int M;
int pre[1048576], rev[1048576];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>M;
    int N=1;
    while(M){
        N<<=1;
        M--;
    }
    for(int i=0;i<N;i++){
        scanf("%d", &pre[i]);
        rev[pre[i]]=i;
        if(i!=0) pre[i]^=pre[i-1];
    }

    // quadratic lol, close but no cigar
    int cnt=0;
    for(int i=0;i<N;i++)
        for(int j=i;j<N;j++){
            int num=pre[j]^(i==0?0:pre[i-1])^(N-1);
            std::cout<<i<<" "<<j<<" "<<num<<" "<<rev[num];
            if(rev[num]<i || rev[num]>j){std::cout<<" AYE"; cnt++;}
            std::cout<<"\n";
        }
    std::cout<<cnt<<"\n";
}

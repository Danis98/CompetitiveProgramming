#include <bits/stdc++.h>

int N, M;
int *row, *tmp;
int cnt=0;

int is_trap(int pos){
    int code=0;
    if(pos>0) code|=row[pos-1]<<2;
    code|=row[pos]<<1;
    if(pos!=N-1) code|=row[pos+1];
    if(code==6 || code==3 || code==4 || code==1)
        return 1;
    return 0;
}

int main(){
    freopen("input.txt", "r", stdin);
    std::cin>>N>>M;
    row=new int[N];
    tmp=new int[N];
    for(int i=0;i<N;i++){
        char c;
        std::cin>>c;
        if(c=='.') row[i]=0;
        else row[i]=1;
        cnt+=1-row[i];
    }
    for(int i=1;i<M;i++){
        for(int j=0;j<N;j++){
            tmp[j]=is_trap(j);
            cnt+=1-tmp[j];
        }
        int *t=tmp;
        tmp=row;
        row=t;
    }

    std::cout<<cnt<<"\n";
}

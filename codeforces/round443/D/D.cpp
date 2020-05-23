#include <bits/stdc++.h>

int N, K, M;
int a[100000];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>K>>M;
    //internal reduction
    int ind=0;
    std::stack<int> beg;
    int len=N;
    for(int i=0;i<N;i++, ind++){
        std::cin>>a[ind];
        if(ind==0){
            beg.push(0);
        }
        else{
            if(a[ind]!=a[ind-1]){
                beg.push(ind);
            }
            if(ind-beg.top()+1==K){
                len-=K;
                ind=beg.top()-1;
                beg.pop();
            }
        }
    }
    //reduction between segments
    ind=len-1;
    int d1=len-1, d2=0;
    while(a[d1]==a[d2] && d1>=d2){
        int v=a[d2];
        while(a[d1]==v && d1>=d2) d1--;
        while(a[d2]==v && d1>=d2) d2++;
        std::cout<<v<<" "<<d1<<" "<<d2<<"\n";
    }
    d1=len-d1-1;
    std::cout<<d1<<" "<<d2<<"\n";
    for(int i=0;i<len;i++)
        std::cout<<a[i]<<" ";
    std::cout<<"\n";
    std::cout<<
}

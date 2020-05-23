#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef std::pair<ull, int> ii;

int N;
ii *evt;
int act;

int main(){
    freopen("input.txt", "r", stdin);
    std::cin>>N;
    evt=new ii[2*N];
    act=0;
    char dash;
    for(int i=0;i<N;i++){
        ull a, b;
        std::cin>>a>>dash>>b;
        if(b==-1) std::cout<<a<<" "<<b<<" AAA\n";
        evt[2*i]={a, 0};
        evt[2*i+1]={b+1, 1};
    }

    std::sort(evt, evt+2*N);

    std::cout<<evt[0].first<<" "<<evt[0].second<<"\n";

    if(evt[0].first>0){
        std::cout<<"0\n";
        return 0;
    }

    int last=0;
    int allowed=0;
    for(int i=0;i<2*N;i++){
        //std::cout<<evt[i].first<<" "<<evt[i].second<<"\n";
        if(evt[i].second==0){
            if(act==0)
                allowed+=evt[i].first-last;
            act++;
        }
        else if(evt[i].second==1) act--;
        last=evt[i].first;
    }
    std::cout<<allowed<<"\n";
}

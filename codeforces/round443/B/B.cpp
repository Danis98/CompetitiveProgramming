#include <bits/stdc++.h>

typedef unsigned long long int ull;

int N;
ull K;
int p[500];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>K;
    for(int i=0;i<N;i++) std::cin>>p[i];
    K=std::min((ull)N-1, K);
    bool win=false;
    int cur=0;
    while(!win){
        bool flag=true;
        for(int i=0;i<K;i++){
            int ind=(cur+i+1)%N;
            if(p[ind]>p[cur]){
                flag=false;
                cur=ind;
                break;
            }
        }
        win=flag;
    }
    std::cout<<p[cur]<<"\n";
}

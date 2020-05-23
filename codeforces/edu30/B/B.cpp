#include <bits/stdc++.h>

int N;
std::string S;
int pre[100001];

std::map<int, int> beg;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>S;
    pre[0]=0;
    beg[0]=0;
    for(int i=1;i<=N;i++){
        pre[i]=pre[i-1]+(S[i-1]-'0')*2-1;
        if(beg.find(pre[i])==beg.end())
            beg[pre[i]]=i;
    }

    int longest=0;
    for(int i=N;i>0;i--){
        if(beg.find(pre[i])==beg.end()) continue;
        longest=std::max(longest, i-beg[pre[i]]);
    }

    std::cout<<longest<<"\n";
}

#include <bits/stdc++.h>

int N, M;
int lett[26], lett_orig[26];
std::string W="";

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    for(int i=0;i<26;i++)
        lett[i]=1;

    std::cin>>N;
    bool unk[N];
    for(int i=0;i<N;i++){
        char ch;
        std::cin>>ch;
        W+=ch;
        if(ch=='*') {unk[i]=true; continue;}
        unk[i]=false;
        lett[ch-'a']=0;
    }
    for(int i=0;i<26;i++)
        lett_orig[i]=lett[i];
    std::cin>>M;
    int freq[26];
    for(int i=0;i<M;i++){
        for(int j=0;j<26;j++) freq[j]=0;
        bool invalid=false;
        for(int j=0;j<N;j++){
            char ch;
            std::cin>>ch;
            if(W[j]!='*' && W[j]!=ch) invalid=true;
            if(lett_orig[ch-'a']==0 && unk[j]) invalid=true;
            freq[ch-'a']=1;
        }
        if(invalid) continue;
        for(int j=0;j<26;j++)
            lett[j]&=freq[j];
    }

    int cnt=0;
    for(int i=0;i<26;i++)
        cnt+=lett[i];

    std::cout<<cnt<<"\n";
}

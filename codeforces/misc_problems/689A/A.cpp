#include <bits/stdc++.h>

int N;
int num[10];

int up[10]={8, -1, -1, -1, 1, 2, 3, 4, 5, 6};
int down[10]={-1, 4, 5, 6, 7, 8, 9, -1, 0, -1};
int left[10]={-1, -1, 1, 2, -1, 4, 5, -1, 7, 8};
int right[10]={-1, 2, 3, -1, 5, 6, -1, 8, 9, -1};

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    std::string s;
    std::cin>>s;
    for(int i=0;i<N;i++) num[i]=s[i]-'0';

    bool res=false, flag=true;
    for(int i=0;i<N;i++)
        if(up[num[i]]==-1) {flag=false; break;}
    res|=flag;
    flag=true;
    for(int i=0;i<N;i++)
        if(down[num[i]]==-1) {flag=false; break;}
    res|=flag;
    flag=true;
    for(int i=0;i<N;i++)
        if(left[num[i]]==-1) {flag=false; break;}
    res|=flag;
    flag=true;
    for(int i=0;i<N;i++)
        if(right[num[i]]==-1) {flag=false; break;}
    res|=flag;
    flag=true;

    if(!res) std::cout<<"YES\n";
    else std::cout<<"NO\n";
}

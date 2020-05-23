#include <bits/stdc++.h>

#define INFTY 1000000000

int maxd[26];
int lastp[26];

std::string S;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    for(int i=0;i<26;i++){
        lastp[i]=-1;
        maxd[i]=-1;
    }

    std::cin>>S;
    for(int i=0;i<S.size();i++){
        int c=S[i]-'a';
        maxd[c]=std::max(maxd[c], i-lastp[c]);
        lastp[c]=i;
    }

    int mink=INFTY;
    for(int i=0;i<26;i++){
        maxd[i]=std::max(maxd[i], (int)S.size()-lastp[i]);
        mink=std::min(mink, maxd[i]);
    }
    std::cout<<mink<<"\n";
}

#include <bits/stdc++.h>

int N, Q;
int pre[50000][26];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::string S;
    std::cin>>S;
    for(int i=0;i<S.size();i++){
        for(int j=0;j<26;j++)
            pre[i][j]=i==0?0:pre[i-1][j];
        pre[i][S[i]-'a']++;
    }

    std::cin>>Q;
    int A, B, C, D;
    int f1[26], f2[26];
    for(int i=0;i<Q;i++){
        std::cin>>A>>B>>C>>D;
        A--;
        B--;
        C--;
        D--;
        for(int j=0;j<26;j++){
            f1[j]=pre[B][j]-(A==0?0:pre[A-1][j]);
            f2[j]=pre[D][j]-(C==0?0:pre[C-1][j]);
        }
        bool eq=true;
        for(int j=0;j<26;j++)
            if(f1[j]!=f2[j]){
                eq=false;
                break;
            }
        if(eq)
            std::cout<<"DA\n";
        else
            std::cout<<"NE\n";
    }
}

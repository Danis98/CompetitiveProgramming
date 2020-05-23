#include <bits/stdc++.h>

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int T, N;
    std::string S;

    std::cin>>T;
    for(int t=0;t<T;t++){
        std::cin>>N>>S;
        bool is_even = (S[N-1]-'0')%2 == 0, sum_even;
        int s = 0;
        for(int i=0;i<N;i++) s += S[i]-'0';
        sum_even = s%2==0;
        int del_ctr = 0;
        for(int i=N-1;i>=0;i--){
            if((S[i]-'0')%2==1){
                if(is_even || i==N-1){is_even = false; continue;}
                is_even = false;
            }
            if(is_even) {del_ctr++;S[i]=' ';}
            else if((S[i]-'0')%2 == 1 && !sum_even){ del_ctr++;S[i] = ' '; sum_even = true; break;}
        }
        if(!is_even && sum_even && del_ctr != N){
            for(int i=0;i<N;i++)
                if(S[i]==' ') continue;
                else std::cout<<S[i];
        }
        else std::cout<<"-1";
        std::cout<<"\n";
    }
}

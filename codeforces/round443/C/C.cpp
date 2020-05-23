#include <bits/stdc++.h>

#define ORIG -1
#define INV  -2
#define ZERO 0
#define ONE  1

int N;
int bits[10];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    for(int i=0;i<10;i++) bits[i]=ORIG;

    std::cin>>N;
    for(int i=0;i<N;i++){
        char op;
        int K;
        std::cin>>op>>K;
        for(int j=9;j>=0;j--){
            int bit=K&1;
            K>>=1;
            switch(op){
                case '|':
                    if(bit==1) bits[j]=1;
                    break;
                case '^':
                    if(bit==1){
                        if(bits[j]==ORIG)
                            bits[j]=INV;
                        else if(bits[j]==INV)
                            bits[j]=ORIG;
                        else if(bits[j]==ONE)
                            bits[j]=ZERO;
                        else if(bits[j]==ZERO)
                            bits[j]=ONE;
                    }
                    break;
                case '&':
                    if(bit==0)
                        bits[j]=ZERO;
                    break;
            }
        }
    }

    int m_cnt=0;
    std::string S;

    //XOR
    int v=0;
    for(int i=0;i<10;i++){
        v<<=1;
        if(bits[i]==INV)
            v|=1;
    }
    if(v!=0){
        m_cnt++;
        S+="^ ";
        S+=std::to_string(v);
        S+="\n";
    }
    //AND
    v=0;
    for(int i=0;i<10;i++){
        v<<=1;
        v|=1;
        if(bits[i]==ZERO)
            v^=1;
    }
    if(v!=1023){
        m_cnt++;
        S+="& ";
        S+=std::to_string(v);
        S+="\n";
    }
    //OR
    v=0;
    for(int i=0;i<10;i++){
        v<<=1;
        if(bits[i]==ONE)
            v|=1;
    }
    if(v!=0){
        m_cnt++;
        S+="| ";
        S+=std::to_string(v);
        S+="\n";
    }

    std::cout<<m_cnt<<"\n"<<S;
}

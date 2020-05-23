#include <bits/stdc++.h>

#define PAIR(X, Y) std::make_pair(X, Y)

#define OP_PLUS     2
#define OP_MINUS    0
#define OP_MULT     3
#define OP_DIV      1

typedef long long int ll;
typedef std::pair<int, int> ii;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::string S;
    std::cin>>S;

    std::vector<ii> num;

    int accum=0;
    for(int i=0;i<S.size();i++){
        if(S[i]>='0' && S[i]<='9')
            accum=accum*10+S[i]-'0';
        else{
            if(S[i]=='+') num.push_back(PAIR(accum, OP_PLUS));
            if(S[i]=='-') num.push_back(PAIR(accum, OP_MINUS));
            if(S[i]=='/') num.push_back(PAIR(accum, OP_DIV));
            if(S[i]=='*') num.push_back(PAIR(accum, OP_MULT));
            accum=0;
        }
    }
    num.push_back(PAIR(accum, -1));

    //MINUS
    for(std::vector<ii>::iterator it=num.begin();it!=num.end();it++)
        while(it->second==OP_MINUS){
            *it={it->first-std::next(it, 1)->first, std::next(it, 1)->second};
            num.erase(std::next(it, 1));
        }
    //DIVIDE
    for(std::vector<ii>::iterator it=num.begin();it!=num.end();it++)
        while(it->second==OP_DIV){
            *it={it->first/std::next(it, 1)->first, std::next(it, 1)->second};
            num.erase(std::next(it, 1));
        }
    //SUM
    for(std::vector<ii>::iterator it=num.begin();it!=num.end();it++)
        while(it->second==OP_PLUS){
            *it={it->first+std::next(it, 1)->first, std::next(it, 1)->second};
            num.erase(std::next(it, 1));
        }
    //MULTIPLY
    for(std::vector<ii>::iterator it=num.begin();it!=num.end();it++)
        while(it->second==OP_MULT){
            *it={it->first*std::next(it, 1)->first, std::next(it, 1)->second};
            num.erase(std::next(it, 1));
        }

    std::cout<<num[0].first<<"\n";
}

#include <bits/stdc++.h>

int N, X;
std::vector<int> switches;

int main(){
    std::cin>>N>>X;
    int t;
    for(int i=0;i<X;i++){
        std::cin>>t;
        switches.push_back(t);
    }
    std::sort(switches.begin(), switches.end());
    int a=0, b=switches.size()-1;
    int da=switches[a]-1, db=N-switches[b];
    int lasta=0, lastb=N+1;
    int destr=0;
    while(a<=b){
        destr+=lastb-lasta-2;
        if(da>=db){lasta=switches[a]; a++;}
        else{lastb=switches[b]; b--;}
        da=switches[a]-lasta-1;
        db=lastb-switches[b]-1;
    }
    std::cout<<destr<<"\n";
}

#include <bits/stdc++.h>

int N;
std::map<int, int> lst;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    lst[0]=1;
    int min=1, rooms=1;
    for(int i=0;i<N;i++){
        int t;
        std::cin>>t;
        if(lst[t]==0){
            rooms++;
            lst[min]=1;
        }
        else{
            lst[t]--;
            lst[min]++;
        }
        min++;
    }

    std::cout<<rooms<<"\n";
}

#include <bits/stdc++.h>

#define P1 37
#define P2 1000000007

typedef unsigned long long int ull;

int N, D;
std::map<ull, int> freq;
int max=0;

ull hash(char *S){
    ull h=0;
    for(int i=0;i<D;i++)
        h=(P1*h+(S[i]-S[0]+26)%26)%P2;
    return h;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>D;
    char S[D+1];
    for(int i=0;i<N;i++){
        scanf("%s", S);
        ull h=hash(S);
        freq[h]++;
        max=std::max(max, freq[h]);
    }

    std::cout<<max<<"\n";
}

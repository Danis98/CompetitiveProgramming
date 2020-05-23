#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
        int N;
        std::cin>>N;
        std::vector<int> b(N), used(2*N+1, 0), max_n(N, -1);
        for(int i=0;i<N;i++){
            std::cin>>b[i];
            used[b[i]] = 1;
        }
        bool imposs = false;
        for(int i=1;i<=2*N;i++){
            if(used[i] == 1) continue;
            bool found = false;
            for(int j=0;j<N;j++)
                if(max_n[j] == -1 && b[j] < i){
                    found = true;
                    max_n[j] = i;
                    break;
                }
            if(!found){
                imposs = true;
                break;
            }
        }
        if(imposs) std::cout<<"-1\n";
        else{
            for(int i=0;i<N;i++) std::cout<<b[i]<<" "<<max_n[i]<<" ";
            std::cout<<"\n";
        }
    }
}

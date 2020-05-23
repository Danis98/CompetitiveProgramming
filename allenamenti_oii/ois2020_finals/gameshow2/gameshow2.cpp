#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int N;
std::vector<int> V, P, C;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N;
    V.resize(N);
    P.resize(N);
    C.resize(N);
    for(int i=0;i<N;i++) std::cin>>V[i];
    for(int i=0;i<N;i++) std::cin>>P[i];
    for(int i=0;i<N;i++) std::cin>>C[i];

    int budg = 0, budg_min = 0, prizes = 0;
    for(int i=0;i<N;i++){
        if(V[i] - P[i] > C[i]){
            prizes += V[i];
            budg -= P[i];
        }
        else budg += C[i];
        budg_min = std::min(budg_min, budg);
    }
    std::cout<<(prizes + budg)<<" "<<(-budg_min)<<"\n";
}

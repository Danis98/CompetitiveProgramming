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
        int N, X;
        std::cin>>N>>X;
        std::vector<int> a(N);
        for(int i=0;i<N;i++)
            std::cin>>a[i];
        std::sort(a.begin(), a.end());
        int r = X+1;
        for(int i=N-1;i>=0;i--){
            if(a[i] == X){
                r = 1;
                break;
            }
            else if(a[i] > X)
                r = std::min(r, 2);
            else{
                r = std::min(r, X / a[i] + (X % a[i] == 0?0:1));
            }
        }
        std::cout<<r<<"\n";
    }
}

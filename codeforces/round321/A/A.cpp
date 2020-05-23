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

    int N;
    std::cin>>N;
    std::vector<int> A(N);
    for(int i=0;i<N;i++) std::cin>>A[i];
    int cur_start = 0, max_so_far = 0;
    for(int i=1;i<N;i++){
        if(A[i] < A[i-1]){
            max_so_far = std::max(max_so_far, i-cur_start);
            cur_start = i;
        }
    }
    max_so_far = std::max(max_so_far, N-cur_start);
    std::cout<<max_so_far<<"\n";
}

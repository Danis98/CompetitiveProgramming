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
    std::vector<ll> A(N);
    for(int i=0;i<N;i++) std::cin>>A[i];
    ll res = 0, res_idx = -1;

    for(int i=0;i<N;i++){
        ll cur_res = A[i], min_so_far = A[i];
        for(int j=i-1;j>=0;j--){
            min_so_far = std::min(A[j], min_so_far);
            cur_res += min_so_far;
        }
        min_so_far = A[i];
        for(int j=i+1;j<N;j++){
            min_so_far = std::min(A[j], min_so_far);
            cur_res += min_so_far;
        }
        if(cur_res > res){
            res = cur_res;
            res_idx = i;
        }
    }

    std::vector<int> out(N);
    out[res_idx] = A[res_idx];
    ll min_so_far = A[res_idx];
    for(int j=res_idx-1;j>=0;j--){
        min_so_far = std::min(A[j], min_so_far);
        out[j] = min_so_far;
    }
    min_so_far = A[res_idx];
    for(int j=res_idx+1;j<N;j++){
        min_so_far = std::min(A[j], min_so_far);
        out[j] = min_so_far;
    }

    for(int i=0;i<N;i++)
        std::cout<<out[i]<<" ";
    std::cout<<"\n";
}

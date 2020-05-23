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
        int N, M;
        std::cin>>N>>M;
        std::vector<int> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        std::vector<bool> cov(N+1, false);
        for(int i=0;i<M;i++){
            int p;
            std::cin>>p;
            p--;
            cov[p] = true;
        }
        bool in_grp = false;
        int cur_s = -1;
        for(int i=0;i<=N;i++){
            if(cov[i] && !in_grp){
                in_grp = true;
                cur_s = i;
            }
            if(!cov[i] && in_grp){
                // std::cout<<cur_s<<" "<<i-1<<"\n";
                std::sort(a.begin()+cur_s, a.begin()+i+1);
                // for(int j=0;j<N;j++) std::cout<<a[j]<<" ";
                // std::cout<<"\n";
                in_grp = false;
            }
        }
        bool ord = true;
        for(int i=0;i<N-1;i++)
            if(a[i] > a[i+1]){
                ord = false;
                break;
            }
        if(ord) std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
}

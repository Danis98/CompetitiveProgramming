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

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        int N;
        std::cin>>N;
        std::vector<ll> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        bool found = false;
        for(int i=0;i<N;i++){
            if(a[i] % 2 == 0){
                found = true;
                std::cout<<"1\n"<<(i+1)<<"\n";
                break;
            }
        }
        if(found) continue;
        ll o1 = -1, o2 = -1;
        for(int i=0;i<N;i++){
            if(a[i] % 2 == 0) continue;
            if(o1 == -1) o1 = i + 1;
            else{
                found = true;
                o2 = i + 1;
                std::cout<<"2\n"<<o1<<" "<<o2<<"\n";
                break;
            }
        }
        if(found) continue;
        std::cout<<"-1\n";
    }
}

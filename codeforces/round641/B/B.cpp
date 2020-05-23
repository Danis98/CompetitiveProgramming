#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        ll N, K;
        std::cin>>N>>K;
        std::vector<ll> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];

        bool present = false;
        for(int i=0;i<N;i++)
            present |= a[i] == K;
        if(!present){
            std::cout<<"no\n";
            continue;
        }

        if(N == 1){
            std::cout<<"yes\n";
            continue;
        }

        bool possible = false;
        for(int i=0;i<N;i++){
            if(a[i] < K) continue;
            if(i > 0 && a[i-1] >= a[i] || i < N-1 && a[i+1] >= a[i]){
                possible = true;
                break;
            }
            if(i > 1 && a[i-2] >= a[i] || i < N-2 && a[i+2] >= a[i]){
                possible = true;
                break;
            }
        }

        if(possible) std::cout<<"yes\n";
        else std::cout<<"no\n";
    }
}

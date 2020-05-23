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
        ll N;
        std::cin>>N;
        std::vector<int> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];

        if(N == 1){
            std::cout<<"0\n";
            continue;
        }

        std::vector<int> pre(N);
        for(int i=0;i<N;i++)
            pre[i] = a[i] + (i > 0 ? pre[i-1] : 0);

        int res = 0;
        for(int i=0;i<N;i++){
            int val = a[i];
            int p1 = 0, p2;
            int sum = a[0];
            for(p2=1;p2<N;p2++){
                sum += a[p2];
                while(sum > val && p1 < p2-1)
                    sum -= a[p1++];
                if(sum == val) break;
            }
            if(sum == val)
                res++;
        }

        std::cout<<res<<"\n";
    }
}

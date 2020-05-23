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
        std::vector<ll> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        int p1 = 0, p2 = N-1;
        ll A = 0, B = 0, prev = 0;
        int ctr = 0;
        while(p1 <= p2){
            if(ctr%2 == 0){
                ll score = 0;
                while(score <= prev && p1 <= p2)
                    score += a[p1++];
                A += score;
                prev = score;
            }
            else{
                ll score = 0;
                while(score <= prev && p1 <= p2)
                    score += a[p2--];
                B += score;
                prev = score;
            }
            ctr++;
        }
        std::cout<<ctr<<" "<<A<<" "<<B<<"\n";
    }
}

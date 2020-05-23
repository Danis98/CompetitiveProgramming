#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

#define MAXN 400005
#define LSB(x) (x&(-x))

struct fenwick{
    ull arr[MAXN];
    fenwick(){
        for(int i=0;i<MAXN;i++) arr[i] = 0;
    }
    void update(int p, int v){
        for(;p<MAXN;p+=LSB(p)) arr[p] += v;
    }
    ull sum(int p){
        ull s = 0;
        for(;p>0;p-=LSB(p)) s += arr[p];
        return s;
    }
    ull sum(int a, int b){
        if(a < 1) return sum(b);
        else return sum(b) - sum(a - 1);
    }
};

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N, M;
    std::vector<int> a;
    std::cin>>M;
    a.resize(M+1);
    for(int i=1;i<=M;i++) std::cin>>a[i];
    std::cin>>N;
    a.resize(N+M+1);
    for(int i=1;i<=N;i++) std::cin>>a[N+M+1-i];

    int ptr = M;
    std::vector<int> pos(N+M+1);
    for(int i=1;i<=N+M;i++) pos[a[i]] = i;

    // for(int i=0;i<N+M;i++) std::cout<<pos[i+1]<<" ";
    // std::cout<<"\n";

    ull tot = 0;
    fenwick F;
    for(int i=1;i<=N+M;i++){
        int dst = pos[i];
        // std::cout<<i<<" AT POS "<<dst<<"\n";
        if(ptr < dst - 1){
            // std::cout<<"POINTER TO "<<(dst-1)<<"\n";
            // std::cout<<"("<<F.sum(ptr+1, dst-1)<<" deleted inbetween)\n";
            tot += (ull)dst - (ull)ptr - 1 - F.sum(ptr+1, dst - 1);
            ptr = dst - 1;
        }
        else if(ptr > dst){
            // std::cout<<"POINTER TO "<<dst<<"\n";
            // std::cout<<"("<<F.sum(dst, ptr)<<" deleted inbetween)\n";
            tot += (ull)ptr - (ull)dst - F.sum(dst, ptr);
            ptr = dst;
        }
        F.update(dst, 1);
        // std::cout<<"TOT="<<tot<<"\n";
    }
    std::cout<<tot<<"\n";
}

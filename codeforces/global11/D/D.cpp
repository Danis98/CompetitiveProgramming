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

int N;
std::vector<ll> a, b;

bool ord(){
    for(int i=0;i<N;i++)
        if(a[i] != i+1) return false;
    return true;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>N;
    a.resize(N);
    b.resize(N);
    for(int i=0;i<N;i++)
        std::cin>>a[i];
    std::stringstream out("");
    int moves = 0;
    while(!ord()){
        int beg = 0;
        while(a[beg] == beg+1) beg++;
        int end = beg+1;
        while(a[end] == a[end-1]+1 && end < N) end++;
        int prev = 0;
        for(int i=0;i<N;i++)
            if(a[i] == a[beg]-1){
                prev = i;
                break;
            }
        // std::cout<<beg<<"("<<a[beg]<<")"<<" "<<end<<" "<<prev<<"\n";
        std::vector<ll> move;
        if(beg > 0)
            move.pb(beg);
        move.pb(end-beg);
        move.pb(prev-end+1);

        if(prev < N-1)
            move.pb(N-prev-1);
        out<<move.size()<<" ";
        int ctra = 0, ctrb = N;
        for(int i=0;i<move.size();i++){
            out<<move[i]<<" ";
            ctrb -= move[i];
            for(int j=0;j<move[i];j++)
                b[ctrb+j] = a[ctra+j];
            ctra += move[i];
        }
        for(int i=0;i<N;i++) a[i] = b[i];
        out<<"\n";
        moves++;
    }
    std::cout<<moves<<"\n";
    std::cout<<out.str();
}

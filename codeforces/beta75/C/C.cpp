#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
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

    std::string A, B;
    std::cin>>A>>B;
    int N = A.length(), M = B.length();

    std::vector<std::vector<int>> next(26, std::vector<int>(N, -1));
    for(int k=0;k<26;k++){
        int min_p = N;
        for(int i=0;i<N;i++)
            if(A[i]-'a' == k){
                min_p = i;
                break;
            }
        if(min_p == N) continue;

        int p = min_p;
        for(int i=1;i<=N;i++){
            next[k][(min_p-i+N)%N] = p;
            if(A[(min_p-i+N)%N]-'a' == k) p = (min_p-i+N)%N;
        }

        // for(int i=0;i<N;i++) std::cout<<next[k][i]<<" ";
        // std::cout<<"\n";
    }

    int pos = A[0]==B[0]? 0 : next[B[0]-'a'][0];
    if(pos == -1){
        std::cout<<"-1\n";
        return 0;
    }
    int piec = 1;
    for(int i=1;i<M;i++){
        int nxt_pos = next[B[i]-'a'][pos];
        if(nxt_pos == -1){
            std::cout<<"-1\n";
            return 0;
        }
        if(nxt_pos <= pos) piec++;
        pos = nxt_pos;
    }

    std::cout<<piec<<"\n";
}

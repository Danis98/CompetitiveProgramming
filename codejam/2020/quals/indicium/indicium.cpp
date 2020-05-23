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

int N = 5;
std::vector<bool> done;
std::vector<std::vector<int>> mat;

void gen(int r, int c){
    if(r == N && c == 0){
        int t = 0;
        for(int i=0;i<N;i++) t += mat[i][i];
        if(done[t]) return;
        std::cout<<"sol[{"<<N<<","<<t<<"}] = \"";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                std::cout<<mat[i][j]<<" ";
            std::cout<<"\\n";
        }
        std::cout<<"\";\n";
        done[t] = true;
        return;
    }
    for(int k=1;k<=N;k++){
        bool v = true;
        for(int i=0;i<c;i++) v &= mat[r][i] != k;
        for(int i=0;i<r;i++) v &= mat[i][c] != k;
        if(!v) continue;
        // std::cout<<r<<" "<<c<<" "<<k<<"\n";
        mat[r][c] = k;
        if(c == N-1) gen(r+1, 0);
        else gen(r, c+1);
        mat[r][c] = 0;
    }
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::map<ii, std::string> sol;
    sol[{2,2}] = "1 2 \n2 1 \n";
    sol[{2,4}] = "2 1 \n1 2 \n";
    sol[{3,6}] = "1 2 3 \n2 3 1 \n3 1 2 \n";
    sol[{3,3}] = "1 2 3 \n3 1 2 \n2 3 1 \n";
    sol[{3,9}] = "3 1 2 \n2 3 1 \n1 2 3 \n";
    sol[{4,4}] = "1 2 3 4 \n2 1 4 3 \n3 4 1 2 \n4 3 2 1 \n";
    sol[{4,6}] = "1 2 3 4 \n2 1 4 3 \n3 4 2 1 \n4 3 1 2 \n";
    sol[{4,8}] = "1 2 3 4 \n2 3 4 1 \n3 4 1 2 \n4 1 2 3 \n";
    sol[{4,10}] = "1 2 3 4 \n2 4 1 3 \n3 1 4 2 \n4 3 2 1 \n";
    sol[{4,9}] = "1 2 3 4 \n2 4 1 3 \n4 3 2 1 \n3 1 4 2 \n";
    sol[{4,7}] = "1 2 3 4 \n3 1 4 2 \n4 3 2 1 \n2 4 1 3 \n";
    sol[{4,12}] = "1 2 3 4 \n3 4 1 2 \n2 3 4 1 \n4 1 2 3 \n";
    sol[{4,11}] = "1 2 3 4 \n3 4 2 1 \n2 1 4 3 \n4 3 1 2 \n";
    sol[{4,13}] = "2 1 3 4 \n3 4 2 1 \n1 3 4 2 \n4 2 1 3 \n";
    sol[{4,14}] = "3 1 2 4 \n1 4 3 2 \n2 3 4 1 \n4 2 1 3 \n";
    sol[{4,16}] = "4 1 2 3 \n1 4 3 2 \n2 3 4 1 \n3 2 1 4 \n";
    sol[{5,14}] = "1 2 3 4 5 \n2 1 4 5 3 \n3 4 5 1 2 \n4 5 2 3 1 \n5 3 1 2 4 \n";
    sol[{5,10}] = "1 2 3 4 5 \n2 1 4 5 3 \n3 4 5 1 2 \n5 3 1 2 4 \n4 5 2 3 1 \n";
    sol[{5,5}] = "1 2 3 4 5 \n2 1 4 5 3 \n3 5 1 2 4 \n4 3 5 1 2 \n5 4 2 3 1 \n";
    sol[{5,8}] = "1 2 3 4 5 \n2 1 4 5 3 \n3 5 1 2 4 \n5 4 2 3 1 \n4 3 5 1 2 \n";
    sol[{5,9}] = "1 2 3 4 5 \n2 1 4 5 3 \n4 5 1 3 2 \n3 4 5 2 1 \n5 3 2 1 4 \n";
    sol[{5,15}] = "1 2 3 4 5 \n2 3 1 5 4 \n3 4 5 1 2 \n4 5 2 3 1 \n5 1 4 2 3 \n";
    sol[{5,12}] = "1 2 3 4 5 \n2 3 1 5 4 \n3 4 5 1 2 \n5 1 4 2 3 \n4 5 2 3 1 \n";
    sol[{5,11}] = "1 2 3 4 5 \n2 3 1 5 4 \n3 5 4 1 2 \n4 1 5 2 3 \n5 4 2 3 1 \n";
    sol[{5,13}] = "1 2 3 4 5 \n2 3 1 5 4 \n5 1 4 2 3 \n4 5 2 3 1 \n3 4 5 1 2 \n";
    sol[{5,16}] = "1 2 3 4 5 \n2 3 4 5 1 \n4 1 5 2 3 \n5 4 1 3 2 \n3 5 2 1 4 \n";
    sol[{5,17}] = "1 2 3 4 5 \n2 4 1 5 3 \n4 3 5 2 1 \n5 1 4 3 2 \n3 5 2 1 4 \n";
    sol[{5,18}] = "1 2 3 4 5 \n2 4 5 1 3 \n3 5 4 2 1 \n4 3 1 5 2 \n5 1 2 3 4 \n";
    sol[{5,19}] = "1 2 3 4 5 \n2 5 1 3 4 \n3 4 5 1 2 \n4 3 2 5 1 \n5 1 4 2 3 \n";
    sol[{5,20}] = "1 2 3 4 5 \n2 5 4 1 3 \n3 4 5 2 1 \n4 3 1 5 2 \n5 1 2 3 4 \n";
    sol[{5,7}] = "1 2 3 4 5 \n3 1 4 5 2 \n4 5 2 1 3 \n5 3 1 2 4 \n2 4 5 3 1 \n";
    sol[{5,21}] = "2 1 3 4 5 \n1 5 4 2 3 \n3 4 5 1 2 \n4 3 2 5 1 \n5 2 1 3 4 \n";
    sol[{5,22}] = "3 1 2 4 5 \n1 5 4 2 3 \n2 4 5 3 1 \n4 3 1 5 2 \n5 2 3 1 4 \n";
    sol[{5,23}] = "4 1 2 3 5 \n1 5 3 4 2 \n2 4 5 1 3 \n3 2 4 5 1 \n5 3 1 2 4 \n";
    sol[{5,25}] = "5 1 2 3 4 \n1 5 3 4 2 \n2 4 5 1 3 \n3 2 4 5 1 \n4 3 1 2 5 \n";

    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++){
        int N, K;
        std::cin>>N>>K;
        std::cout<<"Case #"<<t<<": ";
        if(N > 5 || sol.find({N, K}) == sol.end()) std::cout<<"IMPOSSIBLE\n";
        else std::cout<<"POSSIBLE\n"<<sol[{N, K}];
    }
}

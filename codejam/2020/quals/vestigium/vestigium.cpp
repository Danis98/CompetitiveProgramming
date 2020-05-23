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
    for(int t=1;t<=T;t++){
        int N;
        std::cin>>N;
        std::vector<std::vector<int>> mat(N, std::vector<int>(N));
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                std::cin>>mat[i][j];
        int k = 0;
        for(int i=0;i<N;i++) k += mat[i][i];
        int r = 0, c = 0;
        for(int i=0;i<N;i++){
            std::vector<bool> encr(N+1, false), encc(N+1, false);
            for(int j=0;j<N;j++){
                if(encr[mat[i][j]]){
                    r++;
                    break;
                }
                else encr[mat[i][j]] = true;
            }
            for(int j=0;j<N;j++){
                if(encc[mat[j][i]]){
                    c++;
                    break;
                }
                else encc[mat[j][i]] = true;
            }
        }
        std::cout<<"Case #"<<t<<": "<<k<<" "<<r<<" "<<c<<"\n";
    }
}

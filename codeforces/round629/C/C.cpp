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
        int N;
        std::string C;
        std::cin>>N>>C;
        std::vector<char> A(N, 'X'), B(N, 'Y');
        bool max = false;
        switch(C[0]){
        case '0':
            A[0] = '1';
            B[0] = '2';
            max = true;
            break;
        case '1':
            A[0] = '2';
            B[0] = '2';
            break;
        case '2':
            A[0] = '1';
            B[0] = '1';
            break;
        }
        for(int i=1;i<N;i++){
            if(C[i] == '0'){
                A[i] = '0';
                B[i] = '0';
            }
            else if(C[i] == '1'){
                if(max){
                    A[i] = '1';
                    B[i] = '0';
                }
                else{
                    A[i] = '0';
                    B[i] = '1';
                    max = true;
                }
            }
            else if(C[i] == '2'){
                if(max){
                    A[i] = '2';
                    B[i] = '0';
                }
                else{
                    A[i] = '1';
                    B[i] = '1';
                }
            }
            else{
                std::cout<<"WAT\n";
            }
        }
        for(int i=0;i<N;i++) std::cout<<A[i];
        std::cout<<"\n";
        for(int i=0;i<N;i++) std::cout<<B[i];
        std::cout<<"\n";
    }
}

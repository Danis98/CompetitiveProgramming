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
        std::vector<std::string> P(N);
        for(int i=0;i<N;i++) std::cin>>P[i];
        std::vector<ll> pos(N, 0);
        ll len = P[0].length();
        std::string S = P[0];
        for(int i=1;i<N;i++){
            for(int j=pos[i-1]+1;j<=S.length();j++){
                bool valid = true;
                for(int k=0;k<P[i].length() && k+j<S.length();k++)
                    if(S[j+k] != P[i][k]){
                        valid = false;
                        break;
                    }
                if(valid){
                    pos[i] = j;
                    // std::cout<<i<<" "<<pos[i]<<" "<<P[i].length()<<" "<<S.length()<<std::endl;
                    if(pos[i]+P[i].length() > S.length()){
                        S += P[i].substr(S.length()-pos[i]);
                    }
                    break;
                }
            }
            // std::cout<<S<<std::endl;
        }

        // for(int i=0;i<N;i++)
        //     std::cout<<pos[i]<<" \n"[i==N-1];

        std::cout<<"Case #"<<t<<": "<<S.length()<<"\n";
    }
}

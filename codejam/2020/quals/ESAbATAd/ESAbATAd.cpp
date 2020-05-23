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

    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);

    int T, B;
    std::cin>>T>>B;
    // std::ofstream fout("test_out.txt");
    while(T--){
        std::vector<int> res(B, -1);
        if(B <= 10){
            for(int i=1;i<=10;i++){
                std::cout<<i<<std::endl;
                std::cin>>res[i-1];
            }
            for(int i=0;i<B;i++) std::cout<<res[i];
            std::cout<<std::endl;
        }
        else{
            bool found = false, is_pal = true, is_antipal = true;
            bool beg = false;
            for(int i=0;i<5;i++){
                std::cout<<(i+1)<<std::endl;
                std::cin>>res[i];
                std::cout<<(B-i)<<std::endl;
                std::cin>>res[B-i-1];
            }
            for(int i=0;i<=B/2;i++){
                if(res[i] == -1 || res[B-i-1] == -1) continue;
                if(res[i] == res[B-i-1]) is_antipal = false;
                else is_pal = false;
            }
            int found_bits = 10;
            while(!found){
                int used_q = 0;
                bool inv, trans;
                // check inv, 1 query
                for(int i=0;i<B;i++){
                    if(res[i] == -1 || res[B-i-1] == -1) continue;
                    if(res[i] == res[B-i-1]){
                        int t;
                        std::cout<<(i+1)<<std::endl;
                        std::cin>>t;
                        inv = t != res[i];
                        used_q++;
                        break;
                    }
                }
                if(used_q == 0){
                    int temp;
                    std::cout<<1<<std::endl;
                    std::cin>>temp;
                    used_q++;
                }
                // check trans, 1 query
                for(int i=0;i<B;i++){
                    if(res[i] == -1 || res[B-i-1] == -1) continue;
                    if(res[i] != res[B-i-1]){
                        int t;
                        std::cout<<(i+1)<<std::endl;
                        std::cin>>t;
                        trans = (res[i] != t) ^ inv;
                        used_q++;
                        break;
                    }
                }
                if(used_q == 1){
                    int temp;
                    std::cout<<1<<std::endl;
                    std::cin>>temp;
                    used_q++;
                }
                if(inv) for(int i=0;i<B;i++) if(res[i] != -1) res[i] = 1 - res[i];
                if(trans) for(int i=0;i<B/2;i++) std::swap(res[i], res[B-i-1]);
                // fout<<"ORIG\n";
                // for(int i=0;i<B;i++) fout<<res[i];
                // fout<<"\n";
                // fout<<"["<<(10-used_q)<<" "<<(B-found_bits)<<"]\n";

                int reps = std::min(10-used_q, B-found_bits);
                for(int i=0;i<reps;i++){
                    int idx = -1;
                    for(int i=0;i<=B/2;i++){
                        if(res[i] == -1){
                            idx = i;
                            break;
                        }
                        if(res[B-i-1] == -1){
                            idx = B-i-1;
                            break;
                        }
                    }
                    std::cout<<(idx+1)<<std::endl;
                    std::cin>>res[idx];
                    found_bits++;
                    used_q++;

                    // for(int i=0;i<B;i++) fout<<res[i];
                    // fout<<"\n";
                }
                if(found_bits == B && used_q < 10){
                    // fout<<"Done!\n";
                    found = true;
                }
            }
            for(int i=0;i<B;i++) std::cout<<res[i];
            std::cout<<std::endl;
            // for(int i=0;i<B;i++) fout<<res[i];
            // fout<<std::endl<<std::endl;
        }
        std::string verd;
        std::cin>>verd;
        if(verd == "N") break;
        else continue;
    }
}

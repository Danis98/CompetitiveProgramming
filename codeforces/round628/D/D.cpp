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

ull a, b;
ull d = 0;
int freq[64];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin>>a>>b;
    if(a > b){
        std::cout<<"-1\n";
        return 0;
    }


    ull x = 293341698588646512, y = 101615898083182216, z = 101615898083182216;
    std::vector<int> f(64, 0);
    for(int i=0;i<64;i++){
        f[i] += (x >> i) & 1;
        f[i] += (y >> i) & 1;
        f[i] += (z >> i) & 1;
    }

    std::cout<<"res:\n";
    for(int i=63;i>=0;i--) std::cout<<f[i]<<" ";
    std::cout<<"\n";

    for(int i=63;i>=0;i--) std::cout<<((a >> i)&1)<<" ";
    std::cout<<"\n";
    for(int i=63;i>=0;i--) std::cout<<((b >> i)&1)<<" ";
    std::cout<<"\n";

    for(int i=63;i>=0;i--){
        int b_a = (a >> i) & 1;
        int b_b = (b >> i) & 1;
        if(d == 0){
            if(b_a == 1 && b_b == 0){
                if(i < 62 && freq[i+2] > 1 && freq[i+1] < 2){
                    freq[i-2] -= 2;
                    freq[i-1] += 2;
                    freq[i] = 3;
                    d = 1;
                }
                else{
                    std::cout<<"-1\n";
                    return 0;
                }
            }
            else if(b_a == 1 && b_b == 1){
                freq[i] = 1;
                d = 0;
            }
            else if(b_a == 0 && b_b == 0){
                freq[i] = 0;
                d = 0;
            }
            else if(b_a == 0 && b_b == 1){
                freq[i] = 0;
                d = 1;
            }
        }
        else{
            if(b_a == 1 && b_b == 1){
                freq[i] = 3;
                d = 0;
            }
            else if(b_a == 1 && b_b == 0){
                freq[i] = 1;
                d = 1;
            }
            else if(b_a == 0 && b_b == 1){
                freq[i] = 2;
                d = 1;
            }
            else if(b_a == 0 && b_b == 0){
                freq[i] = 2;
                d = 0;
            }
        }
        std::cout<<freq[i]<<" ";
    }
    for(int i=0;i<64;i++) std::cout<<freq[i]<<" ";
    std::cout<<"\n";
    if(d != 0){
        std::cout<<"-1\n";
        return 0;
    }

    ull a = 0, b = 0, c = 0;
    for(int i=0;i<64;i++){
        if(freq[i] > 0) a |= 1LL << i;
        if(freq[i] > 1) b |= 1LL << i;
        if(freq[i] > 2) c |= 1LL << i;
    }

    if(c == 0){
        if(b == 0){
            if(a == 0) std::cout<<"0\n";
            else std::cout<<"1\n"<<a<<"\n";
        }
        else std::cout<<"2\n"<<a<<" "<<b<<"\n";
    }
    else std::cout<<"3\n"<<a<<" "<<b<<" "<<c<<"\n";
}

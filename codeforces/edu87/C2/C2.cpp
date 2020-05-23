#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define PI 3.14159265358979323846

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        double N;
        std::cin>>N;

        int idx = 0;
        double ext = 0.0;
        while(ext+PI/N < PI/4){
            idx ++;
            ext += PI/N;
        }
        // std::cout<<idx<<"\n";
        double alpha = PI / (2 * N) + idx*PI/N;
        double a = 1.0/(2*std::sin(PI/(2*N)));
        double x = a * std::sin(alpha);
        double y = a * std::cos(alpha);
        double hdiag = x + y;
        // std::cout<<"["<<a<<" "<<alpha<<" "<<x<<" "<<y<<" "<<hdiag<<"]\n";
        double l = std::sqrt(2*hdiag*hdiag);
        printf("%.08f\n", l);
    }
}

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

ll f(ll a, ll b, ll c){
    return (a-b)*(a-b)+(b-c)*(b-c)+(c-a)*(c-a);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        int NA, NB, NC;
        std::cin>>NA>>NB>>NC;
        std::vector<ll> a(NA), b(NB), c(NC);
        for(int i=0;i<NA;i++) std::cin>>a[i];
        for(int i=0;i<NB;i++) std::cin>>b[i];
        for(int i=0;i<NC;i++) std::cin>>c[i];
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        std::sort(c.begin(), c.end());

        ll min = f(a[0], b[0], c[0]);
        ii dir[4] = {
            {-1, 0},
            {1, 0},
            {0, 1},
            {0, -1}
        };
        ii cur_dir = dir[0];
        for(int i=0;i<NA;i++){
            int bl=0, br=NB-1;
            while(br-bl>1){
                int mid = (bl+br)/2;
                if(b[mid] < a[i]) bl = mid;
                else br = mid;
            }
            int cl=0, cr=NC-1;
            while(cr-cl>1){
                int mid = (cl+cr)/2;
                if(c[mid] < a[i]) cl = mid;
                else cr = mid;
            }
            min = std::min(min, f(a[i], b[bl], c[cl]));
            min = std::min(min, f(a[i], b[bl], c[cr]));
            min = std::min(min, f(a[i], b[br], c[cl]));
            min = std::min(min, f(a[i], b[br], c[cr]));
        }
        for(int i=0;i<NB;i++){
            int al=0, ar=NA-1;
            while(ar-al>1){
                int mid = (al+ar)/2;
                if(a[mid] < b[i]) al = mid;
                else ar = mid;
            }
            int cl=0, cr=NC-1;
            while(cr-cl>1){
                int mid = (cl+cr)/2;
                if(c[mid] < b[i]) cl = mid;
                else cr = mid;
            }
            min = std::min(min, f(a[al], b[i], c[cl]));
            min = std::min(min, f(a[al], b[i], c[cr]));
            min = std::min(min, f(a[ar], b[i], c[cl]));
            min = std::min(min, f(a[ar], b[i], c[cr]));
        }

        for(int i=0;i<NC;i++){
            int al=0, ar=NA-1;
            while(ar-al>1){
                int mid = (al+ar)/2;
                if(a[mid] < c[i]) al = mid;
                else ar = mid;
            }
            int bl=0, br=NB-1;
            while(br-bl>1){
                int mid = (bl+br)/2;
                if(b[mid] < c[i]) bl = mid;
                else br = mid;
            }
            min = std::min(min, f(a[al], b[bl], c[i]));
            min = std::min(min, f(a[al], b[br], c[i]));
            min = std::min(min, f(a[ar], b[bl], c[i]));
            min = std::min(min, f(a[ar], b[br], c[i]));
        }
        std::cout<<min<<"\n";
    }
}

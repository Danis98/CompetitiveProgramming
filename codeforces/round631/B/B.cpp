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
        std::cin>>N;
        std::vector<int> a(N);
        for(int i=0;i<N;i++) std::cin>>a[i];
        std::vector<int> freq(N, 0);
        for(int i=0;i<N;i++) freq[a[i]]++;
        int l1=-1, l2=-1;
        for(int i=1;i<N;i++){
            if(freq[i] > 2){
                l1 = l2 = -1;
                break;
            }
            if(freq[i] > 0) l1 = i;
            if(freq[i] > 1) l2 = i;
        }
        if(l1 == -1 || l2 == -1){
            std::cout<<"0\n";
            continue;
        }

        bool beg = true;
        std::vector<bool> pres(N, false);
        for(int i=0;i<l2;i++) pres[a[i]-1] = true;
        for(int i=0;i<l2;i++) beg &= pres[i];
        pres.assign(N, false);
        for(int i=l2;i<N;i++) pres[a[i]-1] = true;
        for(int i=0;i<l1;i++) beg &= pres[i];

        bool end = true;
        pres.assign(N, false);
        for(int i=0;i<l2;i++) pres[a[N-i-1]-1] = true;
        for(int i=0;i<l2;i++) end &= pres[i];
        pres.assign(N, false);
        for(int i=l2;i<N;i++) pres[a[N-i-1]-1] = true;
        for(int i=0;i<l1;i++) end &= pres[i];

        if(beg && end && l2 != l1) std::cout<<"2\n"<<l2<<" "<<l1<<"\n"<<l1<<" "<<l2<<"\n";
        else if(beg) std::cout<<"1\n"<<l2<<" "<<l1<<"\n";
        else if(end) std::cout<<"1\n"<<l1<<" "<<l2<<"\n";
        else std::cout<<"0\n";
    }
}

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

ll N;

int find(std::string pref, ll h){
    int a = 1, b = N-1;
    while(a<b){
        int mid = (a+b)/2;
        int l = mid - a + 1;
        std::string s = pref;
        for(int i=1;i<a;i++) s += "0";
        for(int i=a;i<=mid;i++) s += "1";
        for(int i=mid+1;i<N;i++) s += "0";
        std::cout<<"? "<<s<<std::endl;
        ll res;
        std::cin>>res;
        ll delta = res - h;
        ll w = (l - delta)/2;
        if(pref == "1"){
            if(w == l) a = mid+1;
            else b = mid;
        }
        else if(pref == "0"){
            if(w == 0) a = mid + 1;
            else b = mid;
        }
    }
    return a+1;
}

int main(){
    std::cin>>N;
    std::string s = "";
    for(int i=0;i<N;i++) s+="0";
    std::cout<<"? "<<s<<std::endl;
    ll h0;
    std::cin>>h0;
    s[0] = '1';
    std::cout<<"? "<<s<<std::endl;
    ll h;
    std::cin>>h;
    ll p0 = -1, p1 = -1;
    if(h < h0){
        p1 = 1;
        p0 = find("1", h);
    }
    else{
        p0 = 1;
        p1 = find("0", h);
    }
    std::cout<<"! "<<p0<<" "<<p1<<std::endl;
}

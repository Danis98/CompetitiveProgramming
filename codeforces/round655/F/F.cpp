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

bool dead = false;

void get1(std::vector<ll>& a, ll idx){
    std::cout<<"? "<<idx<<" "<<idx<<std::endl;
    ll x, f;
    std::cin>>x;
    if(x == -1) dead = true;
    std::cin>>f;
    if(dead) return;
    a[idx] = x;
}

void get2(std::vector<ll>& a, ll idx){
    std::cout<<"? "<<idx<<" "<<(idx+1)<<std::endl;
    ll x, f;
    std::cin>>x;
    if(x == -1) dead = true;
    std::cin>>f;
    if(dead) return;
    if(f == 2){
        a[idx] = x;
        a[idx+1] = x;
    }
    else{
        a[idx] = x;
        get1(a, idx+1);
    }
}

void get3(std::vector<ll>& a, ll idx){
    std::cout<<"? "<<idx<<" "<<(idx+2)<<std::endl;
    ll x, f;
    std::cin>>x;
    if(x == -1) dead = true;
    std::cin>>f;
    if(dead) return;
    if(f == 3){
        a[idx] = x;
        a[idx+1] = x;
        a[idx+2] = x;
    }
    if(f == 2){
        ll x1, f1;
        std::cin>>x1;
        if(x1 == -1) dead = true;
        if(dead) return;
        std::cin>>f1;
        if(x1 == x){
            a[idx] = x;
            a[idx+1] = x;
            get1(a, idx+2);
        }
    }
    else if(f==1){
        a[idx] = x;
        get2(a, idx+1);
    }
}

int main(){
    ll N;
    std::cin>>N;
    std::vector<ll> a(N, -1);
    for(int i=0;i<N-(N%4);i+=4){
        std::cout<<"? "<<(i+1)<<" "<<(i+4)<<std::endl;
        ll x, f;
        std::cin>>x>>f;
        if(f==1){
            a[i] = x;
            ll idx = i+1;
            std::cout<<"? "<<idx<<" "<<(idx+3)<<std::endl;
            ll x2, f2;
            std::cin>>x2>>f2;

        }
    }
}

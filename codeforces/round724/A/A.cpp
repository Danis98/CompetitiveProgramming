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
    
    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
    	int N;
    	std::cin>>N;
    	std::set<ll> A;
    	for(int i=0;i<N;i++){
    		ll x;
    		std::cin>>x;
    		A.insert(x);
		}
		bool neg = false;
		for(ll e : A){
			if(e < 0) neg = true;
		}
		bool good = !neg;
    	for(int i=0;i<300;i++){
    		if(!good) break;
    		std::set<ll> to_add;
    		for(ll e : A){
    			for(ll e2 : A){
    				if(e == e2) continue;
    				ll d = std::abs(e-e2);
    				if(A.find(d) == A.end()) to_add.insert(d);
				}
			}
			if(to_add.size() + A.size() > 300){
				good = false;
				break;
			}
			if(to_add.size() == 0) break;
			for(ll e : to_add) A.insert(e);
		}
		if(good){
			std::cout<<"YES\n"<<A.size()<<"\n";
			for(ll e : A) std::cout<<e<<" ";
			std::cout<<"\n";
		}
		else{
			std::cout<<"NO\n";
		}
	}

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
}

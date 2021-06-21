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
    	std::map<ll, ll> nxt, prv;
    	std::cin>>N;
    	std::vector<ll> A(N);
    	for(int i=0;i<N;i++) std::cin>>A[i];
    	
    	ll cur = A[0];
    	bool good = true;
    	for(int i=1;i<N;i++){
    		if(A[i] > cur){
    			if(nxt.find(cur) != nxt.end() && nxt[cur] < A[i]){
    				//std::cout<<cur<<" "<<nxt[cur]<<" "<<A[i]<<"\n";
    				good = false;
    				break;
				}
				if(nxt.find(cur) != nxt.end() && nxt[cur] != A[i]){
					prv[nxt[cur]] = A[i];
					nxt[A[i]] = nxt[cur];
				}
				nxt[cur] = A[i];
				prv[A[i]] = cur;
			}
			if(A[i] < cur){
				if(prv.find(cur) != prv.end() && prv[cur] > A[i]){
    				//std::cout<<cur<<" "<<prv[cur]<<" "<<A[i]<<"\n";
    				good = false;
    				break;
				}
				if(prv.find(cur) != prv.end() && prv[cur] != A[i]){
					nxt[prv[cur]] = A[i];
					prv[A[i]] = prv[cur];
				}
				prv[cur] = A[i];
				nxt[A[i]] = cur;
			}
			cur = A[i];
		}
		if(good) std::cout<<"YES\n";
		else std::cout<<"NO\n";
	}

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
}

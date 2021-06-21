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

ll gcd(ll a, ll b){
	if(a == 0 || b == 0) return std::max(a, b);
	while(b != 0){
		ll t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    
    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
    	int N;
    	std::string S;
    	std::cin>>N>>S;
    	// D = 0, K = 1
    	std::map<ll2, std::vector<ll2>> rpos;
    	std::vector<ll2> ctr(N);
    	ll2 cur_ctr = {0, 0};
    	for(int i=0;i<N;i++){
    		if(S[i] == 'D') cur_ctr.fi++;
    		else cur_ctr.se++;
    		ctr[i] = {cur_ctr.fi, cur_ctr.se};
    		ll d = gcd(cur_ctr.fi, cur_ctr.se);
    		ll2 r = {cur_ctr.fi / d, cur_ctr.se / d};
    		if(rpos.find(r) == rpos.end()){
    			std::cout<<1<<" ";
    			rpos[r] = std::vector<ll2>(1, {1, i});
    			continue;
			}
			else{
				ll best = 1;
				for(int j=rpos[r].size()-1;j>=0;j--){
					ll2 prev = rpos[r][j];
					ll n = prev.fi, e = prev.se;
					ll2 diff = {ctr[i].fi-ctr[e].fi, ctr[i].se-ctr[e].se};
    				ll d2 = gcd(diff.fi, diff.se);
					ll2 rp = {diff.fi / d2, diff.se / d2};
//					std::cout<<i<<" "<<ctr[i].fi<<":"<<ctr[i].se<<" "<<e<<" "<<ctr[e].fi<<":"<<ctr[e].se<<" "<<diff.fi<<":"<<diff.se<<"("<<d2<<")"<<" "<<r.fi<<":"<<r.se<<" "<<rp.fi<<":"<<rp.se<<"\n";
					if(r != rp) continue;
					best = std::max(best, n+1);
					break;
				}
				rpos[r].pb({best, i});
				std::cout<<best<<" ";
			}
		}
		std::cout<<"\n";
	}

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
}

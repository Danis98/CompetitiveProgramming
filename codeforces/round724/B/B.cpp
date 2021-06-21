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
    	std::string S;
    	std::cin>>N>>S;
    	std::string mex = "";
		bool done = false;
    	// l = 1
    	std::vector<bool> vis1(26, false);
    	for(char ch : S) vis1[ch-'a'] = true;
    	for(int i=0;i<26;i++){
    		if(!vis1[i]){
    			mex += ('a'+i);
    			done = true;
    			break;
			}
		}
		if(done){
			std::cout<<mex<<"\n";
			continue;
		}
		
		std::vector<std::vector<int>> vis(26, std::vector<int>(26, 0));
		for(int i=0;i<N-2;i++){
			int x = S[i]-'a', y = S[i+1]-'a', z = S[i+2]-'a';
			vis[x][y] |= 1 << z;
		}
		
		// l = 2
		for(int i=0;i<26;i++){
			for(int j=0;j<26;j++){
				if(vis[i][j] == 0 && !(S[N-2] == 'a'+i && S[N-1] == 'a'+j)){
					done = true;
					mex += 'a' + i;
					mex += 'a' + j;
					break;
				}
			}
			if(done) break;
		}
		if(done){
			std::cout<<mex<<"\n";
			continue;
		}
		
		// l = 3
		for(int i=0;i<26;i++){
			for(int j=0;j<26;j++){
				if(vis[i][j] == (1 << 27)-1) continue;
				for(int k=0;k<26;k++)
					if(((vis[i][j] >> k) & 1) == 0){
						done = true;
						mex += 'a' + i;
						mex += 'a' + j;
						mex += 'a' + k;
						break;
					}
				if(done) break;
			}
			if(done) break;
		}
		std::cout<<mex<<"\n";
	}

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
}

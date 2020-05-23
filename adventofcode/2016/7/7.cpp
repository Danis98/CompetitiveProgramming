#include <bits/stdc++.h>

typedef std::pair<char, char> cc;

int N;

std::map<cc, bool> ssl_mem, ssl_mem_brack;

int main(){
	freopen("input.txt", "r", stdin);
	std::cin>>N;
	std::string S;
	int cnt=0, cnt_ssl=0;
	for(int k=0;k<N;k++){
		std::cin>>S;
		bool is_tls=false, is_ssl=false;
		bool brack=false;
		ssl_mem.clear();
		ssl_mem_brack.clear();
		for(int i=0;i<S.size()-2;i++){
			if(S[i]=='[')
				brack=true;
			else if(S[i]==']')
				brack=false;
			else{
				//TLS
				if(i!=S.size()-2 && S[i]==S[i+3] && S[i+1]==S[i+2] && S[i]!=S[i+1])
					if(brack){
						is_tls=false;
						break;
					}
					else is_tls=true;
				//SSL
				if(S[i]==S[i+2] && S[i]!=S[i+1] && S[i+1]!=']' && S[i+1]!='['){
					std::cout<<brack<<" "<<S[i]<<S[i+1]<<S[i+2]<<"\n";
					if(brack){
						if(ssl_mem[{S[i+1], S[i]}])
							is_ssl=true;
						else ssl_mem_brack[{S[i], S[i+1]}]=true;
					}
					else{
						if(ssl_mem_brack[{S[i+1], S[i]}])
							is_ssl=true;
						else ssl_mem[{S[i], S[i+1]}]=true;
					}
				}
			}
		}
		std::cout<<is_ssl<<"\n";
		if(is_tls) cnt++;
		if(is_ssl) cnt_ssl++;
	}
	std::cout<<cnt<<" "<<cnt_ssl<<"\n";
}

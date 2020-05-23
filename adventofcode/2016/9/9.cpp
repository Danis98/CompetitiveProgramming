#include <bits/stdc++.h>

typedef unsigned long long int ull;

ull len=0, mult_glob=1;
std::map<int, ull> mdiff;

int main(){
	freopen("input.txt", "r", stdin);
	std::string S;
	std::cin>>S;
	bool is_mult=false;
	ull slen=0, mult=0;
	for(int i=0;i<S.size();i++) mdiff[i]=1;
	for(int i=0;i<S.size();i++){
		if(mdiff[i]<0) mult_glob/=-mdiff[i];
		else mult_glob*=mdiff[i];
		if(S[i]=='('){
			is_mult=false;
			slen=0;
			mult=0;
			int j;
			for(j=i+1;j<S.size();j++){
				if(S[j]=='x') is_mult=true;
				else if(S[j]==')') break;
				else{
					if(is_mult) mult=mult*10+S[j]-'0';
					else slen=slen*10+S[j]-'0';
				}
			}
			i=j;
			mdiff[i+1]*=mult;
			mdiff[i+slen+1]=-abs(mdiff[i+slen+1]*mult);
		}
		else len+=mult_glob;
	}
	std::cout<<len<<"\n";
}

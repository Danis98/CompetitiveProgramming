#include <bits/stdc++.h>

typedef std::pair<char, int> ci;

int sum=0;
std::string S;

int main(){
	std::vector<std::string> rooms;
	freopen("input.txt", "r", stdin);
	int ind=0;
	for(int k=0;k<947;k++){
		std::cin>>S;
		ci freq[26];
		for(int i=0;i<26;i++) freq[i]={(char)('a'+i), 0};
		int id=0;
		char check[5];
		int ind=0;
		bool begin_check=false;
		for(int i=0;i<S.size();i++){
			if(S[i]=='-' || S[i]==']') continue;
			else if(S[i]=='[') begin_check=true;
			else if(begin_check) check[ind++]=S[i];
			else{
				if(S[i]>='0' && S[i]<='9') id=10*id+S[i]-'0';
				else freq[S[i]-'a'].second++;
			}
		}
		std::sort(freq, freq+26, [](ci a, ci b){
			if(a.second==b.second) return a.first<b.first;
			return a.second>b.second;
		});
		bool valid=true;
		for(int i=0;i<5;i++)
			if(check[i]!=freq[i].first) valid=false;
		if(valid) sum+=id;
		else continue;

		for(int i=0;i<S.size() && !(S[i]>='0' && S[i]<='9');i++){
			if(S[i]=='-') S[i]=' ';
			else S[i]=(S[i]-'a'+id)%26+'a';
		}
		std::cout<<S<<"\n";
	}
	std::cout<<sum<<"\n";
}

#include <bits/stdc++.h>

int freq[8][26], max[8];

int main(){
	freopen("input.txt", "r", stdin);
	std::string S;

	for(int i=0;i<624;i++){
		std::cin>>S;
		for(int j=0;j<8;j++)
			freq[j][S[j]-'a']++;
	}
	for(int i=0;i<8;i++){
		max[i]=0;
		for(int j=0;j<26;j++)
			if(freq[i][j]<freq[i][max[i]])
				max[i]=j;
	}
	for(int i=0;i<8;i++)
		std::cout<<(char)(max[i]+'a');
	std::cout<<"\n";
}

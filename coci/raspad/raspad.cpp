#include <iostream>
#include <cstdio>

int N, M;
bool **meadow, **id;

int main(){
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	
	std::cin>>N>>M;
	meadow=new bool[N];
	id=new int[N];
	for(int i=0;i<N;i++){
		meadow[i]=new bool[M];
		id=new bool[M];
		for(int j=0;j<M;j++){
			char ch;
			std::cin>>ch;
			meadow=ch=='1';
			id[i][j]=0;
		}
	}
	
}

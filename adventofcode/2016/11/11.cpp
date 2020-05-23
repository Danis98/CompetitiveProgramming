#include <bits/stdc++.h>

//#define START 1048524
#define START 1621
//#define START 299007
#define END 4194303
#define TOT 4194304
#define INFTY 1000000000
#define GET(num, x) (num>>(2*(10-x))&3)
#define SET(num, x, r)				\
	if(r&1) num|=1<<(2*(10-x));		\
	else num&=~(1<<(2*(10-x)));		\
	if(r&2) num|=1<<(2*(10-x)+1);	\
	else num&=~(1<<(2*(10-x)+1));

int dist[TOT], par[TOT];

bool check(int state){
	if(GET(state, 1)!=GET(state, 2)){
		int lev=GET(state, 2);
		if(GET(state, 3)==lev
		|| GET(state, 5)==lev
		|| GET(state, 7)==lev
		|| GET(state, 9)==lev)
			return false;
	}
	if(GET(state, 3)!=GET(state, 4)){
		int lev=GET(state, 4);
		if(GET(state, 1)==lev
		|| GET(state, 5)==lev
		|| GET(state, 7)==lev
		|| GET(state, 9)==lev)
			return false;
	}
	if(GET(state, 5)!=GET(state, 6)){
		int lev=GET(state, 6);
		if(GET(state, 3)==lev
		|| GET(state, 1)==lev
		|| GET(state, 7)==lev
		|| GET(state, 9)==lev)
			return false;
	}
	if(GET(state, 7)!=GET(state, 8)){
		int lev=GET(state, 8);
		if(GET(state, 3)==lev
		|| GET(state, 5)==lev
		|| GET(state, 1)==lev
		|| GET(state, 9)==lev)
			return false;
	}
	if(GET(state, 9)!=GET(state, 10)){
		int lev=GET(state, 10);
		if(GET(state, 3)==lev
		|| GET(state, 5)==lev
		|| GET(state, 7)==lev
		|| GET(state, 1)==lev)
			return false;
	}
	return true;
}

int main(){
	std::queue<int> Q;
	Q.push(START);
	for(int i=0;i<TOT;i++) dist[i]=INFTY;
	dist[START]=0;
	par[START]=START;
	while(!Q.empty()){
		int n=Q.front();
		Q.pop();
		int e=GET(n, 0);
		if(n==END) break;
		/*for(int i=0;i<11;i++)
			std::cout<<GET(n, i)<<" ";
		std::cout<<"\n";*/
		//TRANSPORT SINGLE THING
		for(int i=1;i<11;i++){
			int lev=GET(n, i);
			if(lev!=e) continue;
			if(lev!=0){
				int newn=n;
				SET(newn, 0, lev-1)
				SET(newn, i, lev-1)
				if(check(newn) && dist[newn]>dist[n]+1){
					dist[newn]=dist[n]+1;
					Q.push(newn);
					par[newn]=n;
				}
			}
			if(lev!=3){
				int newn=n;
				SET(newn, 0, lev+1)
				SET(newn, i, lev+1)
				if(check(newn) && dist[newn]>dist[n]+1){
					dist[newn]=dist[n]+1;
					Q.push(newn);
					par[newn]=n;
				}
			}
		}
		//TRANSPORT GEN-CHIP PAIR
		for(int i=1;i<11;i+=2){
			int levg=GET(n, i);
			int levc=GET(n, i-1);
			if(levg!=e) continue;
			if(levg!=levc) continue;
			if(levg!=0){
				int newn=n;
				SET(newn, 0, levg-1)
				SET(newn, i, levg-1)
				SET(newn, i-1, levg-1)
				if(check(newn) && dist[newn]>dist[n]+1){
					dist[newn]=dist[n]+1;
					Q.push(newn);
					par[newn]=n;
				}
			}
			if(levg!=3){
				int newn=n;
				SET(newn, 0, levg+1)
				SET(newn, i, levg+1)
				SET(newn, i-1, levg+1)
				if(check(newn) && dist[newn]>dist[n]+1){
					dist[newn]=dist[n]+1;
					Q.push(newn);
					par[newn]=n;
				}
			}
		}
		//TRANSPORT GEN-GEN PAIR
		for(int i=1;i<11;i+=2){
			for(int j=i+2;j<11;j+=2){
				int levg=GET(n, i);
				int levc=GET(n, j);
				if(levg!=e) continue;
				if(levg!=levc) continue;
				if(levg!=0){
					int newn=n;
					SET(newn, 0, levg-1)
					SET(newn, i, levg-1)
					SET(newn, j, levg-1)
					if(check(newn) && dist[newn]>dist[n]+1){
						dist[newn]=dist[n]+1;
						Q.push(newn);
						par[newn]=n;
					}
				}
				if(levg!=3){
					int newn=n;
					SET(newn, 0, levg+1)
					SET(newn, i, levg+1)
					SET(newn, j, levg+1)
					if(check(newn) && dist[newn]>dist[n]+1){
						dist[newn]=dist[n]+1;
						Q.push(newn);
						par[newn]=n;
					}
				}
			}
		}
		//TRANSPORT CHIP-CHIP PAIR
		for(int i=2;i<11;i+=2){
			for(int j=i+2;j<11;j+=2){
				int levg=GET(n, i);
				int levc=GET(n, j);
				if(levg!=e) continue;
				if(levg!=levc) continue;
				if(levg!=0){
					int newn=n;
					SET(newn, 0, levg-1)
					SET(newn, i, levg-1)
					SET(newn, j, levg-1)
					if(check(newn) && dist[newn]>dist[n]+1){
						dist[newn]=dist[n]+1;
						Q.push(newn);
						par[newn]=n;
					}
				}
				if(levg!=3){
					int newn=n;
					SET(newn, 0, levg+1)
					SET(newn, i, levg+1)
					SET(newn, j, levg+1)
					if(check(newn) && dist[newn]>dist[n]+1){
						dist[newn]=dist[n]+1;
						Q.push(newn);
						par[newn]=n;
					}
				}
			}
		}
	}
	std::cout<<"LOL\n";
	int c=END;
	std::stack<int> path;
	while(c!=par[c]){
		path.push(c);
		c=par[c];
	}
	std::cout<<"\n\n";
	while(!path.empty()){
		for(int i=0;i<11;i++)
			std::cout<<GET(path.top(), i)<<" ";
		std::cout<<"\n";
		path.pop();
	}
	std::cout<<dist[END]<<"\n";
}

#include <bits/stdc++.h>

typedef std::pair<int, int> ii;

int N=231;

int val[101];
ii bots_succ[321], bots_val[321];

void insert_into(int id, int v){
	if(bots_val[id].first==-1){
		bots_val[id].first=v;
		return;
	}
	bots_val[id].second=v;
	if(bots_val[id].second<bots_val[id].first)
		std::swap(bots_val[id].second, bots_val[id].first);
	if(bots_val[id].first==17 && bots_val[id].second==61)
		std::cout<<"BOT "<<id<<" HAS 17 AND 61\n";
	insert_into(bots_succ[id].first, bots_val[id].first);
	insert_into(bots_succ[id].second, bots_val[id].second);
}

int main(){
	freopen("input.txt", "r", stdin);
	for(int i=0;i<100;i++) val[i]=-1;
	for(int i=0;i<321;i++){
		bots_succ[i]={-1, -1};
		bots_val[i]={-1, -1};
	}
	std::string in_type, o1_type, o2_type, temp;
	int in_id, o1_id, o2_id;
	for(int i=0;i<N;i++){
		std::cin>>in_type>>in_id;
		if(in_type=="value"){
			std::cin>>temp>>temp>>o1_type>>o1_id;
			val[in_id]=o1_id;
		}
		else{
			std::cin>>temp>>temp>>temp>>o1_type>>o1_id>>temp>>temp>>temp>>o2_type>>o2_id;
			if(o1_type=="output"){
				if(bots_succ[in_id].first!=-1)
					bots_succ[in_id].second=300+o1_id;
				else
					bots_succ[in_id].first=300+o1_id;
			}
			else{
				if(bots_succ[in_id].first!=-1)
					bots_succ[in_id].second=o1_id;
				else
					bots_succ[in_id].first=o1_id;
			}
			if(o2_type=="output"){
				if(bots_succ[in_id].first!=-1)
					bots_succ[in_id].second=300+o2_id;
				else
					bots_succ[in_id].first=300+o2_id;
			}
			else{
				if(bots_succ[in_id].first!=-1)
					bots_succ[in_id].second=o2_id;
				else
					bots_succ[in_id].first=o2_id;
			}
		}
	}

	for(int i=0;i<100;i++){
		if(val[i]==-1) continue;
		insert_into(val[i], i);
	}

	std::cout<<(bots_val[300].first*bots_val[301].first*bots_val[302].first)<<"\n";
}

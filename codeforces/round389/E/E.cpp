#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

typedef unsigned long long int ull;

int N, K;
std::map<int, std::vector<int>> loga;

int main(){
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif

  std::cin>>N>>K;
  int a;
  for(int i=0;i<N;i++){
    std::cin>>a;
    int p=1, l=0;
    while(p<a){p<<=1; l++;}
    loga[l].push_back(a);
  }
  ull sum=0, add=0;
  int min_log=-1;
  for(auto it=loga.begin();it!=loga.end();it++){
    add=2*add+it->second.size();
    sum+=add;
    if(sum>=N){
      min_log=it->first-1;
      break;
    }
  }
  if(min_log==-1){
    std::cout<<"-1\n";
    return 0;
  }
  int min=100000000;
  for(auto it=loga.begin();it!=loga.end();it++){
    if(it->first<min_log) break;
    for(int i=0;i<it->second.size();it++)
      min=std::min(min, it->second[i]>>(it->first-min_log));
  }
  std::cout<<min<<"\n";
  return 0;
}

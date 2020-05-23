#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

int N, K;
std::map<std::string, std::vector<int>> str;

int main(){
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif

  std::cin>>N>>K;
  std::string S;
  int val;
  for(int i=0;i<N;i++){
    std::cin>>S>>val;
    str[S].push_back(val);
  }

  int beauty=0;
  int center=0;
  for(auto it=str.begin();it!=str.end();it++){
    std::sort(it->second.begin(), it->second.end(), [](int a, int b){return a>b;});
    std::string s=it->first;
    std::string rev=s;
    std::reverse(rev.begin(), rev.end());
    if(str[rev].size()==0 || s>rev) continue;
    if(s==rev){
      
    }
    else{
      std::sort(str[rev].begin(), str[rev].end(), [](int a, int b){return a>b;});
      int len=std::min(it->second.size(), str[rev].size());
      int skip=0;
      for(int i=0;i<len && it->second[i]+str[rev][i]>0;i++)
        beauty+=it->second[i]+str[rev][i];
    }
  }
}

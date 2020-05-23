#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

std::string A, B;
char occ[26];
std::vector<char> pairs;

int main(){
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif

  for(int i=0;i<26;i++) occ[i]='0';
  std::cin>>A>>B;
  for(int i=0;i<A.length();i++){
    if(occ[A[i]-'a']=='0' && occ[B[i]-'a']=='0'){
      occ[A[i]-'a']=B[i];
      occ[B[i]-'a']=A[i];
      if(A[i]!=B[i])
        pairs.push_back(A[i]);
    }
    else{
      if(occ[A[i]-'a']!=B[i] || occ[B[i]-'a']!=A[i]){
        std::cout<<"-1\n";
        return 0;
      }
    }
  }
  std::cout<<pairs.size()<<"\n";
  for(int i=0;i<pairs.size();i++)
    std::cout<<pairs[i]<<" "<<occ[pairs[i]-'a']<<"\n";
}

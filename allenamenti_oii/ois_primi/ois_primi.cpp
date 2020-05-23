#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

std::vector<int> dig;

bool prime[10000001];

bool valid(int n){
  int ind=dig.size()-1;
  while(n>0){
    if(dig[ind]!=-1 && dig[ind]!=n%10)
      return false;
    ind--;
    n/=10;
  }
  return true;
}

void erast(){
  for(int i=0;i<10000001;i++) prime[i]=true;
  prime[0]=false;
  prime[1]=false;
  for(int i=2;i<3162;i++){
    if(!prime[i]) continue;
    for(int j=2*i;j<10000001;j+=i)
      prime[j]=false;
  }
}

int main(){
  char ch;
  while(fin>>ch){
    if(ch=='*') dig.push_back(-1);
    else dig.push_back(ch-'0');
  }
  erast();
  int coeff=1;
  for(int i=0;i<dig.size()-1;i++) coeff*=10;
  int count=0;
  for(int i=dig[0]*coeff;i<(dig[0]+1)*coeff;i++){
    if(!valid(i)) continue;
    if(prime[i]) count++;
  }
  fout<<count<<"\n";
  return 0;
}

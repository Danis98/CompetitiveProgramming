#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <map>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int N;
std::stack<std::string> S;
std::map<std::string, bool> mem;

int main(){
  fin>>N;
  std::string a;
  for(int i=0;i<N;i++){
    fin>>a;
    S.push(a);
  }
  while(!S.empty()){
    a=S.top();
    S.pop();
    if(mem[a]) continue;
    mem[a]=true;
    fout<<a<<"\n";
  }
  return 0;
}

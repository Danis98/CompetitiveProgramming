#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

std::string S1, S2;
std::deque<char> A, B;
std::stack<char> S;

void crossover(std::deque<char>& a, std::deque<char>& b){
  if(a.size()==0 || b.size()==0){
    for(int i=0;i<a.size();i++) fout<<a[i];
    for(int i=0;i<b.size();i++) fout<<b[i];
    while(!S.empty()){ fout<<S.top(); S.pop(); }
    return;
  }
  else if(a[0]==b[b.size()-1]){
    a.pop_front();
    b.pop_back();
    crossover(b, a);
  }
  else{
    fout<<b[b.size()-1];
    S.push(a[0]);
    a.pop_front();
    b.pop_back();
    crossover(a, b);
  }
}

int main(){
  fin>>S1>>S2;
  for(int i=0;i<S1.length();i++) A.push_back(S1[i]);
  for(int i=0;i<S2.length();i++) B.push_back(S2[i]);

  crossover(A, B);
}

#include <iostream>
#include <cstdio>

int N, M, K;

int main(){
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif

  std::cin>>N>>M>>K;
  int r=(K-1)/(2*M);
  int d=((K-1)%(2*M))/2;
  std::cout<<(r+1)<<" "<<(d+1)<<" "<<(K%2==0?'R':'L')<<"\n";
  return 0;
}

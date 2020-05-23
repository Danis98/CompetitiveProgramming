#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

typedef unsigned long long int ull;
typedef std::pair<int, int> ii;

#define LSB(x) x&(-x)

int N;
ii *A;
ull *fenw;

void update(int n, int v){
  for(;n<=N;n+=LSB(n))
    fenw[n]+=v;
}

ull query(int n){
  ull s=0;
  for(;n>0;n-=LSB(n))
    s+=fenw[n];
  return s;
}

int main(){
  fin>>N;
  fenw=new ull[N+1];
  A=new ii[N];
  fenw[N]=0;
  for(int i=0;i<N;i++){
    fenw[i]=0;
    fin>>A[i].first;
    A[i].second=i;
  }
  std::sort(A, A+N);

  ull inv=0;
  for(int i=0;i<N;i++){
    int ind=A[i].second;
    inv+=ind-query(ind+1);
    update(ind+1, 1);
  }

  fout<<inv<<"\n";
}

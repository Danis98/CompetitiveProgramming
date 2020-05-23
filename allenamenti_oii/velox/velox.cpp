#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include <cstdio>

FILE *fr=fopen("input.txt", "r");
std::ofstream fout("output.txt");

#define getch getc_unlocked

int read_int(){
    int n=0;
    char ch;
    while((ch=getch(fr))>='0')
        n=10*n+ch-'0';
    return n;
}

typedef std::pair<int, int> ii;

int N, M;
std::vector<std::vector<ii>> G;

std::map<ii, int> mem;

int dfs(int n, int v){
  ii p={n, v};
  if(mem.find(p)!=mem.end()) return mem[p];
  mem[p]=0;
  for(int i=0;i<G[n].size();i++){
    if(G[n][i].second>v)
      mem[p]=std::max(mem[p], dfs(G[n][i].first, G[n][i].second)+1);
  }
  return mem[p];
}

int main(){
  N=read_int();
  M=read_int();
  G.resize(N);
  int a, b, w;
  for(int i=0;i<M;i++){
    a=read_int();
    b=read_int();
    w=read_int();
    G[a].push_back({b, w});
  }

  int M=0;
  for(int i=0;i<N;i++)
    M=std::max(M, dfs(i, 0));

  fout<<M<<"\n";
}

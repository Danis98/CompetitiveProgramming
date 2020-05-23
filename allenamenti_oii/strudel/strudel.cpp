#include <bits/stdc++.h>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int *tree;

void update(int a, int b, int p, int v, int pos){
  if(p<a || b<p) return;
  if(a==b){
    tree[pos]=v;
    return;
  }
  int m=(a+b)/2;
  update(a, m, p, v, 2*pos+1);
  update(m+1, b, p, v, 2*pos+2);
  tree[pos]=std::max(tree[2*pos+1], tree[2*pos+2]);
}

int query(int a, int b, int qa, int qb, int val, int pos){
  if(qb<a || b<qa) return -1;
  if(a==b) return a;
  int m=(a+b)/2;
//  std::cout<<"SEARCHING FOR n>="<<val<<" IN "<<a<<"-"<<b<<", ("<<tree[2*pos+1]<<", "<<tree[2*pos+2]<<")\n";
  if(tree[2*pos+2]>=val) return query(m+1, b, qa, qb, val, 2*pos+2);
  else return query(a, m, qa, qb, val, 2*pos+1);
}

int N;
int *a, *b, *r;

int main(){
  fin>>N;
  a=new int[N];
  b=new int[N];
  r=new int[N];
  int p=1;
  while(p<N) p<<=1;
  tree=new int[2*p-1];
  for(int i=0;i<2*p-1;i++) tree[i]=INT_MIN;
  for(int i=0;i<N;i++) fin>>a[i];
  for(int i=0;i<N;i++) fin>>b[i];
  for(int i=0;i<N;i++) r[i]=b[i]-a[i];

  int pre[N];
  pre[0]=r[0];
  for(int i=1;i<N;i++) pre[i]=pre[i-1]+r[i];
  for(int i=0;i<N;i++) update(0, p-1, i, pre[i], 0);
//  for(int i=0;i<2*p-1;i++) std::cout<<tree[i]<<" ";
//  std::cout<<"\n";

  int q=query(0, p-1, 1, N-1, 0, 0);
  int res=q==-1?0:q+1;

/*  for(int i=0;i<N;i++) std::cout<<r[i]<<" ";
  std::cout<<"\n";
  for(int i=0;i<N;i++) std::cout<<pre[i]<<" ";
  std::cout<<"\n";*/

  for(int i=1;i<N-1;i++){
    //std::cout<<"RIGHTEST pre[i>"<<i<<"] is at ";
    int l=i, r=query(0, p-1, i+1, N-1, pre[i], 0);
    if(r==-1) continue;
    res=std::max(res, r-l+1);
  }

  fout<<res<<"\n";
}

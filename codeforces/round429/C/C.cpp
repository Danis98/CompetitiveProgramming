#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef std::pair<ull, int> li;

int N;
li *A, *B;

int main(){
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif

  scanf("%d", &N);
  A=new li[N];
  B=new li[N];
  ull t;
  for(int i=0;i<N;i++){
    scanf("%lld", &t);
    A[i]={t, i};
  }
  for(int i=0;i<N;i++){
    scanf("%lld", &t);
    B[i]={t, i};
  }

  std::sort(A, A+N, [](li a, li b){
    return a.first>b.first;
  });
  std::sort(B, B+N);

  int res[N];
  for(int i=0;i<N;i++)
    res[B[i].second]=A[i].first;
  for(int i=0;i<N;i++)
    std::cout<<res[i]<<" ";
  std::cout<<"\n";
}

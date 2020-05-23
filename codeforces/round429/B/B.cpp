#include <bits/stdc++.h>

typedef unsigned long long int ull;

int N;
ull *arr;

int main(){
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif

  std::cin>>N;
  arr=new ull[N];
  for(int i=0;i<N;i++){
    scanf("%lld", &arr[i]);
    if(arr[i]%2==1){
      std::cout<<"First\n";
      return 0;
    }
  }
  std::cout<<"Second\n";
  return 0;
}

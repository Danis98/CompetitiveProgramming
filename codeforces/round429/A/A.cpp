#include <bits/stdc++.h>

int N, K;
int freq[26];

int main(){
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif

  memset(freq, 0, sizeof(freq));
  std::cin>>N>>K;
  char c;
  for(int i=0;i<N;i++){
    std::cin>>c;
    freq[c-'a']++;
  }

  for(int i=0;i<26;i++){
    if(freq[i]>K){
      std::cout<<"NO\n";
      return 0;
    }
  }
  std::cout<<"YES\n";
  return 0;
}

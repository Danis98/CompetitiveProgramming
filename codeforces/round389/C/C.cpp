#include <iostream>
#include <cstdio>

int N;
char hor='0', ver='0';
int len=1;

int main(){
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif

  std::cin>>N;
  char ch;
  for(int i=0;i<N;i++){
    std::cin>>ch;
    if(ch=='L' || ch=='R'){
      if(hor!=ch && hor!='0'){
        len++;
        ver='0';
      }
      hor=ch;
    }
    else{
      if(ver!=ch && ver!='0'){
        len++;
        hor='0';
      }
      ver=ch;
    }
  }
  std::cout<<len<<"\n";
  return 0;
}

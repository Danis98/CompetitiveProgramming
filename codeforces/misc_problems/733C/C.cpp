#include <bits/stdc++.h>

typedef long long int ll;

int N, K;
ll A[500], B[500];

std::string moves="";

bool check_sub(int a, int b, int d){
    if(a==b) return true;
    //std::cout<<"[DBG] "<<a<<" "<<b<<" "<<d<<"\n";
    bool flag=true;
    for(int i=a;i<b;i++) if(A[i]!=A[i+1]){flag=false; break;}
    if(flag) return false;

    std::vector<int> maxind;
    ll maxv=0;
    for(int i=a;i<=b;i++)
        if(A[i]==maxv) maxind.push_back(i);
        else if(A[i]>maxv){maxind.clear(); maxind.push_back(i); maxv=A[i];}

    int curindx;
    for(int i=maxind.size()-1;i>=0;i--){
        int ind=maxind[i];
        if((ind==b || A[ind+1]==A[ind]) && A[ind-1]==A[ind]) continue;
        curindx=ind-d+1;
        if(A[ind+1]==A[ind] && ind!=b) {moves+=std::to_string(curindx)+" L\n"; curindx--;}
        for(int j=0;j<b-ind;j++) moves+=std::to_string(curindx)+" R\n";
        for(;curindx>a-d+1;curindx--) moves+=std::to_string(curindx)+" L\n";
        break;
    }

    return true;
}

int main(){
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif

  std::cin>>N;
  for(int i=0;i<N;i++) std::cin>>A[i];
  std::cin>>K;
  for(int i=0;i<K;i++) std::cin>>B[i];

  int d=0, ind=0, beg=0;
  ll sum=0;
  for(int i=0;i<N;i++){
      sum+=A[i];
      if(sum==B[ind]){
          if(!check_sub(beg, i, d)){
              std::cout<<"NO\n";
              return 0;
          }
          d=i-ind;
          sum=0;
          beg=i+1;
          ind++;
      }
      if(sum>B[ind]){
          std::cout<<"NO\n";
          return 0;
      }
  }
  if(ind!=K) std::cout<<"NO\n";
  else std::cout<<"YES\n"<<moves;
}

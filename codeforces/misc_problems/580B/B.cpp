#include <bits/stdc++.h>

#define MAXN ((1LL<<31)-1)
#define PAIR(X, Y) std::make_pair(X, Y)

typedef long long int ll;
typedef std::pair<ll, ll> ll2;

int N;
ll D;
ll2 a[100000];
ll cum[100000];

int main(){
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif

  std::cin>>N>>D;
  for(int i=0;i<N;i++) std::cin>>a[i].first>>a[i].second;
  std::sort(a, a+N);

  cum[0]=a[0].second;
  for(int i=1;i<N;i++) cum[i]=cum[i-1]+a[i].second;

  ll res=cum[std::upper_bound(a, a+N, PAIR(a[0].first+D-1, MAXN))-a-1];
  for(int i=1;i<N;i++){
      ll val=cum[std::upper_bound(a, a+N, PAIR(a[i].first+D-1, MAXN))-a-1]-cum[i-1];
      res=std::max(res, val);
  }
  std::cout<<res<<"\n";
}

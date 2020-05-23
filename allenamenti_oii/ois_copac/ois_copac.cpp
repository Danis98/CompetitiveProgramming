#include <bits/stdc++.h>

int N;
std::vector<std::vector<int>> tree;
int sub[100000];
std::vector<int> centr;

#define getchar getc_unlocked
#define putchar putc_unlocked

int read_int(){
  char ch=getchar(stdin);
  int n=0;
  while(ch<'0') ch=getchar(stdin);
  for(;ch>='0';ch=getchar(stdin))
    n=10*n+ch-'0';

  return n;
}

void print_int(int n){
  if(n==0){
    putchar('0', stdout);
    return;
  }
  int l=0;
  char dig[12];
  while(n>0){
    dig[l++]='0'+n%10;
    n/=10;
  }

  for(int i=l-1;i>=0;i--)
    putchar(dig[i], stdout);
}

void dfs(int n, int p){
    sub[n]=1;
    for(auto it=tree[n].begin();it!=tree[n].end();it++){
        if(*it==p) continue;
        dfs(*it, n);
        sub[n]+=sub[*it];
    }
}

void find_centroid(int n, int p){
    for(auto it=tree[n].begin();it!=tree[n].end();it++){
        if(*it==p) continue;
        if(sub[*it]*2>=N){
            find_centroid(*it, n);
            return;
        }
    }
    centr.push_back(n+1);
    if((N-sub[n])*2>=N)
        centr.push_back(p+1);
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    //std::cin>>N;
    N=read_int();
    tree.resize(N);
    int x, y;
    for(int i=0;i<N-1;i++){
        //std::cin>>x>>y;
        x=read_int()-1;
        y=read_int()-1;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(0, -1);

    find_centroid(0, -1);

    std::sort(centr.begin(), centr.end());
    for(auto it=centr.begin();it!=centr.end();it++){
        print_int(*it);
        putchar('\n', stdout);
    }
}

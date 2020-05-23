#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>

#define LSB(x) x&(-x)

struct fenwick_tree{
    int N;
    int *arr;
    fenwick_tree(int N): N(N){
        arr=new int[N+1];
        for(int i=0; i<N; i++) arr[i]=0;
    }
    void update(int n, int v){
        if(n>N) return;
        for(; n<=N; n += LSB(n))
            arr[n] += v;
    }
    int query(int n){
        int res=0;
        for(; n>0; n-= LSB(n))
            res += arr[n];
        return res;
    }

    int range(int a, int b){
        return query(b)-query(a-1);
    }
};

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int N;
    std::map<std::string, int> names;
    std::vector<int> A;
    do{
        std::cin>>N;
        if(N==0) break;
        names.clear();
        A.clear();
        A.resize(N);
        for(int i=0;i<N;i++){
            std::string word;
            std::cin>>word;
            names[word] = i;
        }

        for(int i=0;i<N;i++){
            std::string word;
            std::cin>>word;
            A[names[word]] = i;
        }

        fenwick_tree fenw(N);
        int ctr = 0;

        for(int i=0;i<N;i++){
            ctr += fenw.range(A[i]+1, N);
            fenw.update(A[i]+1, 1);
        }

        std::cout<<ctr<<"\n";
    } while(N!=0);
}

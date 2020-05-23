#include <bits/stdc++.h>

int N, M, K;
int a[100][100];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M>>K;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            std::cin>>a[i][j];

    int score=0, del=0;
    for(int c=0;c<M;c++){
        int n=0;
        while(n<N && a[n][c]==0) n++;
        int sum=0;
        for(int i=n;i<N && i<n+K;i++) sum+=a[i][c];
        int colmax=sum;
        int ind=0, del_col=0;
        for(int i=n;i<N;i++){
            if(a[i][c]==1){
                if(colmax<sum){
                    del_col=ind;
                    colmax=sum;
                }
                ind++;
            }
            //std::cout<<i<<" "<<sum<<"\n";
            sum-=a[i][c];
            if(i+K<N) sum+=a[i+K][c];
        }
        //std::cout<<"col "<<c<<" -> "<<colmax<<" "<<del_col<<"\n";
        score+=colmax;
        del+=del_col;
    }

    std::cout<<score<<" "<<del<<"\n";
}

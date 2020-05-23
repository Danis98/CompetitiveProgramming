#include <iostream>
#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int N, K, *p;

int main(){
    fin>>K>>N;
    p=new int[N];
    for(int i=0;i<N;i++) fin>>p[i];

    int prof=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N && j<=i+K;j++)
            if(p[j]-p[i]>prof) prof=p[j]-p[i];
    }
    fout<<prof;
}

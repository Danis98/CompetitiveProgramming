#include <iostream>
#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int N, *arr;

int main(){
    fin>>N;
    arr=new int[N];
    for(int i=0;i<N;i++) fin>>arr[i];

    int T=1;
    for(int i=1;i<N;i++)
        if(arr[i-T]!=arr[i]) T=i;
std::cout<<N<<" "<<T<<"\n";
    if(T==N-1 || N%T!=0)
        fout<<"2\n";
    else
        for(int i=0;i<T;i++)
            fout<<arr[i]<<" ";
}

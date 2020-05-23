//Problem        : Tracing Vile Angus
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

#define MAXN 1000

int N;
string S;
int pos[MAXN];
char f[MAXN], s[MAXN];

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    getline(cin, S);
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>pos[i]>>f[i]>>s[i];

    for(int i=N-1;i>=0;i--){
        for(int j=pos[i];j<S.size();j++){
            //cout<<S[j]<<f[i]<<s[i]<<(char)(f[i]+'A'-'a')<<(char)(s[i]+'A'-'a')<<"\n";
            if(S[j]==f[i] || S[j]==f[i]+'A'-'a') S[j] += s[i]-f[i];
            else if(S[j]==s[i] || S[j]==s[i]+'A'-'a') S[j] += f[i]-s[i];
        }
    }

    cout<<S<<"\n";

    return 0;
}

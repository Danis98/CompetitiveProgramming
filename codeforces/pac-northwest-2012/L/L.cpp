#include <iostream>
#include <string>

std::string S="", temp, plain="";

std::string vowels = "aiyeou";
std::string consonants = "bkxznhdcwgpvjqtsrlmf";

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    while(std::cin>>temp)
        S += (S=="" ? "" : " ") + temp;
    for(int i=0;i<S.length();i++){
        char ch = S[i];
        if(ch>='a' && ch<='z'){
            int p=vowels.find(ch);
            if(p == std::string::npos)
                plain += consonants[(consonants.find(ch)+10)%20];
            else plain += vowels[(p+3)%6];
        }
        else if(ch>='A' && ch<='Z'){
            ch -= 'A' - 'a';
            int p=vowels.find(ch);
            if(p == std::string::npos)
                plain += consonants[(consonants.find(ch)+10)%20]+'A'-'a';
            else plain += vowels[(p+3)%6]+'A'-'a';
        }
        else plain += ch;
    }
    std::cout<<plain;
}

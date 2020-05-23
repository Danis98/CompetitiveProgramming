#include <bits/stdc++.h>

typedef std::pair<int, char> ic;

int N;
int freq[62];

int ch_to_id(char ch){
    if(ch>='a' && ch<='z') return ch-'a';
    if(ch>='A' && ch<='Z') return ch-'A'+26;
    if(ch>='0' && ch<='9') return ch-'0'+52;
    return -1;
}

char id_to_char(int id){
    if(id<26) return 'a'+id;
    if(id<52) return 'A'+id-26;
    if(id-62) return '0'+id-52;
    return '#';
}

int find_nonzero(){
    for(int i=0;i<62;i++)
        if(freq[i]!=0) return i;
    return -1;
}

int find_disp(){
    for(int i=0;i<62;i++)
        if(freq[i]%2!=0) return i;
    return -1;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    for(int i=0;i<62;i++) freq[i]=0;
    std::cin>>N;
    for(int i=0;i<N;i++){
        char ch;
        std::cin>>ch;
        freq[ch_to_id(ch)]++;
    }

    int disp=0;
    for(int i=0;i<62;i++)
        if(freq[i]%2==1)
            disp++;

    int psum=0;
    for(int i=0;i<62;i++)
        psum+=freq[i]-freq[i]%2;

    bool found=false;
    for(int p=std::max(1, disp);p<N && !found;p+=2){
        if(N%p!=0) continue;
        std::string pals[p];
        if((N/p)%2!=0){
            for(int i=0;i<p;i++){
                int d=find_disp();
                if(d==-1) d=find_nonzero();
                pals[i]+=id_to_char(d);
                freq[d]--;
            }
        }

        for(int i=0;i<62;i++)
            if(freq[i]%2==1)
                continue;

        if(((N-p)/2)%p!=0) continue;

        found=true;
        for(int i=0;i<p;i++){
            int l=N/(2*p);
            //std::cout<<"BUILDING STRING "<<i<<"\n";
            while(l>0){
                int c=find_nonzero();
                //printf("%c %d\n", id_to_char(c), freq[c]);
                int mult=std::min(l, freq[c]/2);
                for(int j=0;j<mult;j++)
                    pals[i]+=id_to_char(c);
                freq[c]-=mult*2;
                l-=mult;
            }
        }
        printf("%d\n", p);
        for(int i=0;i<p;i++){
            for(int j=pals[i].size()-1;j>=0;j--)
                printf("%c", pals[i][j]);
            for(int j=(N/p)%2;j<pals[i].size();j++)
                printf("%c", pals[i][j]);
            printf(" ");
            fflush(stdout);
        }
    }
    if(!found){
        printf("%d\n", N);
        for(int i=0;i<62;i++)
            for(int j=0;j<freq[i];j++){
                printf("%c ", id_to_char(i));
                fflush(stdout);
            }
    }
    printf("\n");
}

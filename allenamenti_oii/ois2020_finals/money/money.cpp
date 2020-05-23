#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int N, M;
std::vector<ii> bal;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>M;
    bal.resize(N);
    for(int i=0;i<N;i++) bal[i] = {0, i};
    for(int i=0;i<M;i++){
        int a, b, c;
        std::cin>>a>>b>>c;
        bal[a].first -= c;
        bal[b].first += c;
    }
    std::sort(bal.begin(), bal.end());
    int ind = N-1;
    int num_trans = 0;
    // for(int i=0;i<N;i++) std::cout<<bal[i].first<<","<<bal[i].second<<" ";
    // std::cout<<"\n";
    std::vector<iii> trans;
    while(ind >= 0){
        if(bal[ind].first == 0) ind--;
        else{
            int amt = bal[ind].first;
            int snd = bal[ind].second;
            int dst;
            for(int j=ind-1;j>=0;j--)
                if(bal[j].first != 0){
                    dst = j;
                    break;
                }
            bal[dst].first += amt;
            bal[ind].first -= amt;
            ind = dst;
            num_trans++;
            // std::cout<<"SEND "<<amt<<" FROM "<<snd<<" TO "<<bal[dst].second<<"\n";
            // for(int i=0;i<N;i++) std::cout<<bal[i].first<<","<<bal[i].second<<" ";
            // std::cout<<"\n";
            if(amt < 0) break;
            trans.push_back({amt, {snd, bal[dst].second}});
        }
    }
    std::cout<<num_trans<<"\n";
    for(int i=0;i<num_trans;i++)
        std::cout<<trans[i].second.first<<" "<<trans[i].second.second<<" "<<trans[i].first<<"\n";
}

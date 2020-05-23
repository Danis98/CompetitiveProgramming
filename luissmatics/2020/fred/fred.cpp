#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<ll, ll2> ll3;
typedef std::pair<double, double> dd;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

void split(const std::string& str, std::vector<std::string>& cont,
              char delim = ' '){
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    for(int t=1;t<=T;t++){
        std::cout<<"Case #"<<t<<": ";
        int M;
        std::cin>>M;
        std::vector<std::string> name(M);
        std::map<std::string, int> name_inv;
        std::vector<double> L(M, 0), R(M, 0), G(M, 0);
        for(int i=0;i<M;i++){
            std::cin>>name[i];
            name_inv[name[i]] = i;
        }
        std::vector<ll> N(M);
        for(int i=0;i<M;i++) std::cin>>N[i];
        std::string dummy;
        std::getline(std::cin, dummy);
        for(int i=0;i<M;i++){
            for(int j=0;j<N[i];j++){
                std::string l1, l2;
                std::getline(std::cin, l1);
                std::getline(std::cin, l2);
                std::vector<std::string> words;
                std::vector<std::string> likes;
                split(l1, words);
                split(l2, likes);
                L[i] += (double)words.size()/N[i];
                for(std::string like : likes){
                    if(name[i] != like) R[i]++;
                    G[name_inv[like]]++;
                }
            }
        }

        // for(int i=0;i<M;i++)
        //     std::cout<<L[i]<<" "<<R[i]<<" "<<G[i]<<"\n";

        std::vector<std::pair<double, std::string>> rank;
        for(int i=0;i<M;i++)
            rank.pb({L[i]*R[i]/(G[i]+1), name[i]});
        std::sort(rank.begin(), rank.end(), [](std::pair<double, std::string> a, std::pair<double, std::string> b){
            if(a.fi == b.fi) return a.se < b.se;
            return a.fi > b.fi;
        });
        std::cout<<rank[0].se<<"\n";
    }
}

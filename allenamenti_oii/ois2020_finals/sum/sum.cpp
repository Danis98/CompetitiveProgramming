#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int N;
std::string A, B, C, resA, resB;
std::vector<std::vector<ii>> pairs(10);
std::vector<int> ass(26, -1);
std::vector<char> ass_inv(10, ' ');

bool explore(int pos, int dig){
    if(pos < 0) return false;
    char chA = A[pos], chB = B[pos];
    if(chA == ' ' || chB == ' ') return dig == 0;
    int dA = ass[chA - 'A'], dB = ass[chB - 'A'];
    for(ii poss : pairs[dig]){
        if(dA != -1 && dA != poss.first) continue;
        if(dB != -1 && dB != poss.second) continue;
        if(ass_inv[poss.first] != ' ' && ass_inv[poss.first] != chA) continue;
        if(ass_inv[poss.second] != ' ' && ass_inv[poss.second] != chB) continue;
        if(chA != chB && poss.first == poss.second) continue;
        if(chA == chB && poss.first != poss.second) continue;
        int pdA = dA, pdB = dB;
        char pdAi = ass_inv[poss.first], pdBi = ass_inv[poss.second];
        ass[chA - 'A'] = poss.first;
        ass[chB - 'A'] = poss.second;
        ass_inv[poss.first] = chA;
        ass_inv[poss.second] = chB;
        // std::cout<<"POS "<<pos<<": "<<poss.first<<" "<<poss.second<<" "<<ass_inv[poss.first]<<" "<<ass_inv[poss.second]<<", "<<chA<<" "<<chB<<"\n";
        if(pos == 0 && (poss.first+poss.second)<10 && poss.first != 0 && poss.second != 0 || explore(pos-1, C[pos-1] - '0' - (poss.first + poss.second)/10)){
            resA += poss.first + '0';
            resB += poss.second + '0';
            return true;
        }
        ass[chA - 'A'] = pdA;
        ass[chB - 'A'] = pdB;
        ass_inv[poss.first] = pdAi;
        ass_inv[poss.second] = pdBi;
    }
    return false;
}

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>A>>B>>C;
    int N = A.length();
    if(C.length() > N){
        A = " " + A;
        B = " " + B;
    }
    N = C.length();

    for(int i=0;i<10;i++) for(int j=0;j<10;j++){
        pairs[(i+j)%10].push_back({i, j});
    }

    explore(N-1, C[N-1]-'0');

    std::cout<<resA<<"\n"<<resB<<"\n";
}

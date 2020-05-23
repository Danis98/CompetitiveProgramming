#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::string S;
    std::cin>>S;
    int N = S.length();
    std::vector<int> pre_open(N), post_close(N);
    for(int i=0;i<N;i++){
        if(i > 0)
            pre_open[i] = pre_open[i-1];
        if(S[i] == '(')
            pre_open[i]++;
    }
    for(int i=N-1;i>=0;i--){
        if(i < N-1)
            post_close[i] = post_close[i+1];
        if(S[i] == ')')
            post_close[i]++;
    }
    int m_idx = -1, m_val = 0;
    for(int i=0;i<N;i++){
        int v = std::min(pre_open[i], post_close[i]);
        if(m_val < v){
            m_idx = i;
            m_val = v;
        }
    }
    if(m_idx == -1){
        std::cout<<"0\n";
    }
    else{
        std::cout<<"1\n"<<(2*m_val)<<"\n";
        int ctr = 0;
        for(int i=0;i<=m_idx;i++)
            if(S[i] == '('){
                std::cout<<i+1<<" ";
                ctr++;
                if(ctr >= m_val) break;
            }
        ctr = 0;
        std::vector<int> p;
        for(int i=N-1;i>=m_idx;i--)
            if(S[i] == ')'){
                p.push_back(i+1);
                ctr++;
                if(ctr >= m_val) break;
            }
        for(int i=p.size()-1;i>=0;i--) std::cout<<p[i]<<" ";
        std::cout<<"\n";
    }
}

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

    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
        int N;
        std::string S;
        std::cin>>N>>S;
        std::vector<ii> segs;

        ii cur_seg = {0, 1};
        for(int i=0;i<N-1;i++){
            if(S[i] == '<') cur_seg.second++;
            else{
                segs.push_back(cur_seg);
                cur_seg = {i+1, 1};
            }
        }
        segs.push_back(cur_seg);
        // for(int i=0;i<segs.size();i++)
        //     std::cout<<segs[i].first<<","<<segs[i].second<<"\n";
        // std::cout<<"\n";

        std::vector<int> seq(N);
        int cur = 0, min = 0;
        for(int i=0;i<segs.size();i++){
            int sstart = segs[i].first;
            int ssize = segs[i].second;
            for(int j=0;j<ssize;j++){
                seq[sstart+j] = -sstart+j-ssize;
                min = std::min(min, seq[sstart+j]);
            }
        }
        for(int i=0;i<N;i++) std::cout<<(seq[i]-min+1)<<" ";
        std::cout<<"\n";

        segs.clear();
        cur_seg = {0, 1};
        for(int i=0;i<N-1;i++){
            if(S[i] == '>') cur_seg.second++;
            else{
                segs.push_back(cur_seg);
                cur_seg = {i+1, 1};
            }
        }
        segs.push_back(cur_seg);
        // for(int i=0;i<segs.size();i++)
        //     std::cout<<segs[i].first<<","<<segs[i].second<<"\n";
        // std::cout<<"\n";

        seq.clear();
        cur = 0;
        min = 0;
        for(int i=0;i<segs.size();i++){
            int sstart = segs[i].first;
            int ssize = segs[i].second;
            for(int j=0;j<ssize;j++) seq[sstart+j] = sstart+ssize-j-1;
        }
        for(int i=0;i<N;i++) std::cout<<(seq[i]-min+1)<<" ";
        std::cout<<"\n";
    }
}

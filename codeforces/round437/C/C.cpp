#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair<ll, ll> ii;
typedef std::pair<ll, ii> iii;

int N, S;
iii *cont;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>S;
    cont=new iii[N];
    for(int i=0;i<N;i++)
        std::cin>>cont[i].first>>cont[i].second.first>>cont[i].second.second;
    std::sort(cont, cont+N, [](iii a, iii b){
        ll d1=a.second.first-a.second.second;
        ll d2=b.second.first-b.second.second;
        return d1>d2;
    });
    ll tot=0;
    for(int i=0;i<N;i++) tot+=cont[i].first;
    ll ind=0, used=0;
    ll maxh=0;
    while(tot>0){
        ll pizz=S;
        ll tota=0, totb=0;
        while(pizz>0){
            if(ind>=N) break;
            ll left=cont[ind].first-used;
            if(left>pizz){
                tota+=pizz*cont[ind].second.first;
                totb+=pizz*cont[ind].second.second;
                used+=pizz;
                pizz=0;
            }
            else{
                tota+=left*cont[ind].second.first;
                totb+=left*cont[ind].second.second;
                used=0;
                pizz-=left;
                ind++;
            }
        }
        tot-=S;
        maxh+=std::max(tota, totb);
    }
    std::cout<<maxh<<"\n";
}

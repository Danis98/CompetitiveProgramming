#include <bits/stdc++.h>

typedef long long int ll;
typedef std::pair<ll, ll> ll2;

class comp{
public:
    bool operator()(const ll2& a, const ll2& b) const{
        return std::max(a.first, a.second)<std::max(b.first, b.second);
    }
};

int N;
ll X1, Y1, X2, Y2;
ll r1=0, r2=0;

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>X1>>Y1>>X2>>Y2;
    std::priority_queue<ll2, std::vector<ll2>, comp> Q;
    for(int i=0;i<N;i++){
        ll X, Y;
        std::cin>>X>>Y;
        ll d1=(X-X1)*(X-X1)+(Y-Y1)*(Y-Y1);
        ll d2=(X-X2)*(X-X2)+(Y-Y2)*(Y-Y2);
        Q.push({d1, d2});
    }

    for(int i=0;i<N;i++){
        ll d1=Q.top().first;
        ll d2=Q.top().second;
        Q.pop();
        if(d1<=r1 || d2<=r2) continue;
        if(d1+r2<r1+d2) r1=d1;
        else r2=d2;
    }
    std::cout<<(r1+r2)<<"\n";
}

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

#define MAXV 1000000000

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        ll N, K;
        std::string S;
        std::cin>>N>>K>>S;
        ll score = 2*N - 1;
        ll rem = 0;
        for(int i=0;i<N;i++)
            if(S[i] == 'L') rem++;
        rem = std::max(0LL, rem - K);
        ll a = 0, b = N-1;
        std::vector<ll> scores(N);
        for(int i=0;i<N;i++){
            if(S[i] == 'W') scores[i] = MAXV;
            ll sc = 3;
            if(i == 0) sc--;
            if(i == N-1) sc--;
            scores[i] = sc;
        }
        std::vector<ll> trail(N, 0);
        for(int i=N-2;i>=0;i--)
            if(S[i] == 'L' && S[i+1] == 'L')
                trail[i] = trail[i+1]+1;
        std::priority_queue<ll3, std::vector<ll3>, std::greater<ll3>> Q;
        for(int i=0;i<N;i++)
            if(S[i] == 'L')
                Q.push({scores[i], {-trail[i], i}});
        while(rem && !Q.empty()){
            ll3 cur = Q.top();
            Q.pop();
            ll sc = cur.fi, n = cur.se.se;
            if(S[n] == 'X') continue;
            score -= sc;
            S[n] = 'X';
            if(n > 0 && S[n-1] == 'L') Q.push({scores[n-1]-1, {-trail[n-1], n-1}});
            if(n < N-1 && S[n+1] == 'L') Q.push({scores[n+1]-1, {-trail[n+1], n+1}});
            //std::cout<<"DELETING "<<n<<" FOR "<<sc<<"\n";
            rem--;
        }
        score = std::max(0LL, score);
        std::cout<<score<<"\n";
    }
}

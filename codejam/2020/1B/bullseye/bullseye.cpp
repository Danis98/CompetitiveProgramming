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

#define S 1000000000L

int main(){
    // std::ofstream fout("out.txt");

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll T, A, B;
    std::cin>>T>>A>>B;
    while(T--){
        // fout<<"STARTING\n";
        bool hit = false;
        bool center = false;
        bool exceeded = false;
        ll x, y;
        while(!hit){
            x = (rand() % (2*S)) - S;
            y = (rand() % (2*S)) - S;
            std::cout<<x<<" "<<y<<std::endl;
            std::string resp;
            std::cin>>resp;
            if(resp == "HIT") hit = true;
            else if(resp == "CENTER"){
                hit = true;
                center = true;
            }
            else if(resp == "WRONG"){
                exceeded = true;
                break;
            }
        }
        if(center) continue;
        if(exceeded) break;
        // fout<<"FOUND HIT\n";
        int moves = 0;
        ll ra = x, rb = S;
        while(ra < rb){
            ll mid = ra+rb < 0 ? (ra+rb)/2 : (ra+rb+1)/2;
            std::cout<<mid<<" "<<y<<std::endl;
            std::string resp;
            std::cin>>resp;
            moves++;
            if(resp == "HIT") ra = mid;
            else if(resp == "CENTER"){
                center = true;
                break;
            }
            else if(resp == "WRONG"){
                exceeded = true;
                break;
            }
            else rb = mid - 1;
        }
        if(center) continue;
        if(exceeded) break;
        dd right = {ra, y};
        // fout<<"RIGHT IN "<<moves<<"\n";
        ll la = -S, lb = x;
        while(la < lb){
            ll mid = la+lb < 0 ? (la+lb-1)/2 : (la+lb)/2;
            std::cout<<mid<<" "<<y<<std::endl;
            std::string resp;
            std::cin>>resp;
            moves++;
            if(resp == "HIT") lb = mid;
            else if(resp == "CENTER"){
                center = true;
                break;
            }
            else if(resp == "WRONG"){
                exceeded = true;
                break;
            }
            else la = mid + 1;
        }
        if(center) continue;
        if(exceeded) break;
        dd left = {la, y};
        // fout<<"LEFT IN "<<moves<<"\n";
        ll ua = -S, ub = y;
        while(ua < ub){
            ll mid = ua+ub < 0 ? (ua+ub-1)/2 : (ua+ub)/2;
            std::cout<<x<<" "<<mid<<std::endl;
            std::string resp;
            std::cin>>resp;
            moves++;
            if(resp == "HIT") ub = mid;
            else if(resp == "CENTER"){
                center = true;
                break;
            }
            else if(resp == "WRONG"){
                exceeded = true;
                break;
            }
            else ua = mid + 1;
        }
        if(center) continue;
        if(exceeded) break;
        dd up = {x, ua};
        // fout<<"UP IN "<<moves<<"\n";
        ll da = y, db = S;
        while(da < db){
            ll mid = da+db < 0 ? (da+db)/2 : (da+db+1)/2;
            std::cout<<x<<" "<<mid<<std::endl;
            std::string resp;
            std::cin>>resp;
            moves++;
            if(resp == "HIT") da = mid;
            else if(resp == "CENTER"){
                center = true;
                break;
            }
            else if(resp == "WRONG"){
                exceeded = true;
                break;
            }
            else db = mid - 1;
        }
        if(center) continue;
        if(exceeded) break;
        dd down = {x, da};
        // fout<<"DOWN IN "<<moves<<"\n";

        dd ctr = {(left.fi+right.fi)/2, (up.se+down.se)/2};
        // fout<<ctr.fi<<" "<<ctr.se<<"\n";
        for(int i=(int)ctr.fi-5;i<=(int)ctr.fi+5 && !center && !exceeded;i++)
            for(int j=(int)ctr.se-5;j<=(int)ctr.se+5 && !center && !exceeded;j++){
                std::cout<<i<<" "<<j<<std::endl;
                std::string resp;
                std::cin>>resp;
                // fout<<i<<" "<<j<<" "<<resp<<"\n";
                if(resp == "CENTER"){
                    center = true;
                    break;
                }
                else if(resp == "WRONG"){
                    exceeded = true;
                    break;
                }
            }
        // if(center) fout<<"FOUND CENTER\n";
    }
}

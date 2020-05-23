#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

// int choices[7][3] = {
//     {0, 0, 1},
//     {0, 1, 0},
//     {1, 0, 0},
//     {1, 1, 0},
//     {1, 0, 1},
//     {0, 1, 1},
//     {1, 1, 1}
// };

// int rec(int num[3]){
//     int res = 0;
//     for(int i=0;i<7;i++){
//         bool valid = true;
//         for(int j=0;j<3;j++)
//             if(num[j] < choices[i][j])
//                 valid = false;
//         if(!valid) continue;
//         for(int j=0;j<3;j++) num[j] -= choices[i][j];
//         if(valid) res = std::max(res, rev(num) + 1);
//         for(int j=0;j<3;j++) num[j] += choices[i][j];
//     }
//     return res;
// }

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int T;
    std::cin>>T;
    for(int t=0;t<T;t++){
        int num[3];
        std::cin>>num[0]>>num[1]>>num[2];
        std::sort(num, num+3);
        std::swap(num[0], num[2]);
        int num_g = 0;
        for(int i=0;i<3;i++)
            if(num[i] > 0){
                num[i]--;
                num_g++;
            }
        for(int i=0;i<3;i++)
            for(int j=i+1;j<3;j++)
                if(num[i] > 0 && num[j] > 0){
                    num[i]--;
                    num[j]--;
                    num_g++;
                }
        if(num[0] > 0 && num[1] > 0 && num[2] > 0)
            num_g++;
        std::cout<<num_g<<"\n";
    }
}

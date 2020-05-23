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

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        std::vector<std::string> sudoku(9);
        for(int i=0;i<9;i++)
            std::cin>>sudoku[i];
        sudoku[0][0] = std::max(1, (sudoku[0][0]-'0'+1)%10)+'0';
        sudoku[1][3] = std::max(1, (sudoku[1][3]-'0'+1)%10)+'0';
        sudoku[2][6] = std::max(1, (sudoku[2][6]-'0'+1)%10)+'0';
        sudoku[3][1] = std::max(1, (sudoku[3][1]-'0'+1)%10)+'0';
        sudoku[4][4] = std::max(1, (sudoku[4][4]-'0'+1)%10)+'0';
        sudoku[5][7] = std::max(1, (sudoku[5][7]-'0'+1)%10)+'0';
        sudoku[6][2] = std::max(1, (sudoku[6][2]-'0'+1)%10)+'0';
        sudoku[7][5] = std::max(1, (sudoku[7][5]-'0'+1)%10)+'0';
        sudoku[8][8] = std::max(1, (sudoku[8][8]-'0'+1)%10)+'0';
        for(int i=0;i<9;i++)
            std::cout<<sudoku[i]<<"\n";
    }
}

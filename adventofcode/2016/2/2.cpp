#include <bits/stdc++.h>

char keypad[5][5]={
	{' ', ' ', '1', ' ', ' '},
	{' ', '2', '3', '4', ' '},
	{'5', '6', '7', '8', '9'},
	{' ', 'A', 'B', 'C', ' '},
	{' ', ' ', 'D', ' ', ' '},
};

int main(){
	freopen("input.txt", "r", stdin);
	int x=1, y=1;
	std::string S;
	do{
		std::getline(std::cin, S);
		if(S[0]!='U' && S[0]!='D' && S[0]!='L' && S[0]!='R') break;
		for(int i=0;i<S.size();i++){
			switch(S[i]){
				case 'U':
					if(y>0 && keypad[y-1][x]!=' ') y--;
					break;
				case 'D':
					if(y<4 && keypad[y+1][x]!=' ') y++;
					break;
				case 'L':
					if(x>0 && keypad[y][x-1]!=' ') x--;
					break;
				case 'R':
					if(x<4 && keypad[y][x+1]!=' ') x++;
					break;
			}
		}
		std::cout<<keypad[y][x];
	}while(!std::cin.eof());
	std::cout<<"\n";
}

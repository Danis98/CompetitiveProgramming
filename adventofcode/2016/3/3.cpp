#include <bits/stdc++.h>

int N=1902;

int main(){
	freopen("input.txt", "r", stdin);

	int a[3], b[3], c[3];
	int cnt=0;
	for(int i=0;i<N;i+=3){
		std::cin>>a[0]>>b[0]>>c[0];
		std::cin>>a[1]>>b[1]>>c[1];
		std::cin>>a[2]>>b[2]>>c[2];
		std::sort(a, a+3);
		std::sort(b, b+3);
		std::sort(c, c+3);
		if(a[0]+a[1]>a[2]) cnt++;
		if(b[0]+b[1]>b[2]) cnt++;
		if(c[0]+c[1]>c[2]) cnt++;
	}
	std::cout<<cnt<<"\n";
}

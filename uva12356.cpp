#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva12356.in");
ofstream fout("uva12356.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
int S,Lost,L,R;

int v[100002][2],l,r;
int main(){
	redirect();
	while(scanf("%d %d",&S,&Lost)){
		if(S==0&&Lost==0)
			break;
		
		for(int i=1;i<=S;i++){
			v[i][0]=i-1;
			v[i][1]=i+1;
		}
	

		for(int i=0;i<Lost;i++){
			scanf("%d %d",&L,&R);
			v[L-1][1]=v[R][1];
			v[R+1][0]=v[L][0];

			v[v[L][0]][1]=v[R][1];
			v[v[R][1]][0]=v[L][0];

			r=v[L-1][1];
			l=v[R+1][0];
			if(!(1<=l&&l<=S))
				printf("* ");
			else
				printf("%d ",l);
			if(!(1<=r&&r<=S))
				printf("*");
			else
				printf("%d",r);
			printf("\n");
		}
		printf("-\n");  
	}
	return 0;
}
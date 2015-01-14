//#include <iostream>
#include "stdio.h"
#include <algorithm>
#include "string.h"
using namespace std;
int M[30][30],P,N,a,b,city=0;;

int main(){

	while(scanf("%d",&P)==1){
		N=0;
        memset(M,0,sizeof(M));
		for(int i=0;i<P;i++){
           scanf("%d %d",&a,&b);
           //cin>>a>>b;
		   M[a][b]=1;
		   N=max(N,max(a,b));
		}
		N++;
		for(int k=0;k<N;k++)
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					M[i][j]+=M[i][k]*M[k][j];
		for(int k=0;k<N;k++)
			if(M[k][k]){
		     for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					if(M[i][k]&&M[k][j])
						M[i][j]=-1;
			}
		printf("matrix for city %d\n",city);
		//cout<<"matrix for city "<<city<<endl;
		city++;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				printf("%d",M[i][j]);
				//cout<<M[i][j];
				if(j!=N-1)
                printf(" ");
				 //cout<<" ";
				else
				printf("\n");
			}
	}
	return 0;
}
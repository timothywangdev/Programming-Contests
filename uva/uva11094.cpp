// land and water letters can be different from 'w' and 'l'.

#include <iostream>
#include <algorithm>
using namespace std;

int N,M,x,y,maximum;
int mo[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
char m[20][20];
char land,water;
int search(int r,int c){
   int sum=1;
   m[r][c]=water;
   for(int i=0;i<4;i++){
	   int x=r+mo[i][0];
	   int y=c+mo[i][1];
	   if(y==M){
		   y=0;
	   }
	   else if(y==-1){
		   y=M-1;
	   }
	   if(0<=x&&x<N&&m[x][y]==land){
		   sum+=search(x,y);
	   }
   }
   return sum;
}
int main(){
    while(cin>>N>>M){
    	for(int i=0;i<N;i++){
    		for(int j=0;j<M;j++){
    			cin>>m[i][j];
    		}
    	}
    	cin>>x>>y;
    	land=m[x][y];
    	water=land-1;
    	maximum=search(x,y);
    	maximum=0;
    	for(int i=0;i<N;i++){
    	    for(int j=0;j<M;j++){
              if(m[i][j]==land){
            	  maximum=max(maximum,search(i,j));
              }
    	    }
    	}
    	cout<<maximum<<endl;
    }
	return 0;
}

//#define DEBUG
//#include <fstream>
//#include <iostream>
#include "stdio.h"
#define MAXIMUM 2147483647
//using namespace std;

#ifdef DEBUG
ifstream fin("uva116.in");
ofstream fout("uva116.out");
#endif

int f[100][10];
int p[100][10];
int m[10][100];
int R,C,minvalue,themin;
void display(int i,int j){
     if(i==-1)
		 return;
	 
#ifdef DEBUG
	 if(j!=0)
		 fout<<i+1<<" ";
	 else
		 fout<<i+1<<endl;
#else
	 if(j!=0)
         printf("%d ",i+1);
		 //cout<<i+1<<" ";
	 else
		 printf("%d\n",i+1);
		 //cout<<i+1<<endl;
#endif
	 display(p[j][i],j-1);
}
int main(){
#ifdef DEBUG
	while(fin>>R>>C){
      for(int i=0;i<R;i++)
		  for(int j=0;j<C;j++)
             fin>>m[i][C-j-1];
#else
    while(scanf("%d %d",&R,&C)==2){
      for(int i=0;i<R;i++)
		  for(int j=0;j<C;j++)
             //cin>>m[i][C-j-1];
			 scanf("%d",&m[i][C-j-1]);

#endif
	  for(int i=0;i<C;i++)
		  for(int j=0;j<R;j++)
			  if(i==0){
                 f[i][j]=m[j][i];
				 p[i][j]=-1;
			  }
			  else{
			     f[i][j]=f[i-1][j];
				 p[i][j]=j;

				 if(f[i-1][(j-1+R)%R]<f[i][j]){
                   f[i][j]=f[i-1][(j-1+R)%R];
				   p[i][j]=(j-1+R)%R;
				 }
				 else if(f[i-1][(j-1+R)%R]==f[i][j]&&((j-1+R)%R)<p[i][j]){
                   p[i][j]=(j-1+R)%R;
				 }

                 if(f[i-1][(j+1)%R]<f[i][j]){
                   f[i][j]=f[i-1][(j+1)%R];
				   p[i][j]=(j+1)%R;
				 }
				 else if(f[i-1][(j+1)%R]==f[i][j]&&((j+1)%R)<p[i][j]){
                   p[i][j]=(j+1)%R;
				 }
				 f[i][j]+=m[j][i];
			  }
	  minvalue=MAXIMUM;
	  for(int i=0;i<R;i++)
		  if(f[C-1][i]<minvalue){
             themin=i;
			 minvalue=f[C-1][i];
		  }
	  display(themin,C-1);
	  #ifdef DEBUG
	  fout<<minvalue<<endl;
	  #else
	  //cout<<minvalue<<endl;
	  printf("%d\n",minvalue);
	  #endif
	}
}
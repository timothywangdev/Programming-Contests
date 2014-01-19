//#define DEBUG
#include "string.h"
#include <iostream>
using namespace std;
#define MAXIMUM 168430090


#ifdef DEBUG
#include <fstream>
ifstream fin("uva104.in");
ofstream fout("uva104.out");
#endif


double f[20][20][21];
int pathMiddle[20][20][21];
int pathLeftSteps[20][20][21];
int N;

void display(int from,int dest,int steps){
	if(pathMiddle[from][dest][steps]==MAXIMUM){
       #ifdef DEBUG
		fout<<from+1<<" ";
       #else
        cout<<from+1<<" ";
       #endif
		return;
	}

	display(from,pathMiddle[from][dest][steps],pathLeftSteps[from][dest][steps]);
    display(pathMiddle[from][dest][steps],dest,steps-pathLeftSteps[from][dest][steps]);
}

int main(){
    #ifdef DEBUG
		while(fin>>N){
    #else
        while(cin>>N){
    #endif
       for(int i=0;i<20;i++)
		   for(int j=0;j<20;j++)
			   for(int k=0;k<21;k++)
				   f[i][j][k]=0;
	   memset(pathMiddle,10,sizeof(pathMiddle));

	   for(int i=0;i<N;i++)
		   for(int j=0;j<N;j++)
			   if(i!=j)
			   {
				   #ifdef DEBUG
				   fin>>f[i][j][1];
				   #else
				   cin>>f[i][j][1];
				   #endif
			   }
			   else{
				   f[i][j][1]=1;
			   }

      try
	  {
	   for(int steps=2;steps<=N;steps++)
	   {

		 for(int k=0;k<N;k++)
		  for(int i=0;i<N;i++)
		   for(int j=0;j<N;j++)
		    for(int ss=1;ss<steps;ss++)
			 //if(i!=j&&k!=i&&k!=j)
			   if(f[i][j][steps]<f[i][k][ss]*f[k][j][steps-ss])
			   {
                 f[i][j][steps]=f[i][k][ss]*f[k][j][steps-ss];
				 pathMiddle[i][j][steps]=k;
				 pathLeftSteps[i][j][steps]=ss;
			   }
	  
	     for(int start=0;start<N;start++)
		  for(int middle=0;middle<N;middle++)
		   if(middle!=start)
			for(int ss=1;ss<steps;ss++)
			 if(f[start][middle][ss]*f[middle][start][steps-ss]>1.01)
			  {			  
			    pathMiddle[start][start][steps]=middle;
			    pathLeftSteps[start][start][steps]=ss;
			    display(start,start,steps);
				throw start+1;
			  }
	    }
	    throw -1;
	  }
	  catch(int start)
	  {  if(start>=1){
		  #ifdef DEBUG
		  fout<<start<<endl;
          #else
		  cout<<start<<endl;
		  #endif
	     }
	     else{
		  #ifdef DEBUG
		  fout<<"no arbitrage sequence exists"<<endl;
          #else
		  cout<<"no arbitrage sequence exists"<<endl;
		  #endif	
		 }
	  }
  }
 return 0;
}
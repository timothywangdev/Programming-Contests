#include <iostream>
#include <fstream>
#include "string.h"

using namespace std;
#ifdef DEBUG
ifstream fin("uva141.in");
ofstream fout("uva141.out");
#endif
bool state[100][50][50];
bool rotate[3][50][50];
int N,S,r,c;
char sign;
bool repeated,continueSign;
void add(int r,int c){
   state[S][r][c]=true;
}
void remove(int r,int c){
   state[S][r][c]=false;
}
void saveState(){
   S++;
}
/*
void display(){
  fout<<"--------START START---------"<<endl;
  for(int i=0;i<N;i++){
	   for(int j=0;j<N;j++)
		   fout<<state[S-1][i][j]<<" ";
	   fout<<endl;
	}
  fout<<"==================================="<<endl;
  for(int p=0;p<3;p++){
	 for(int i=0;i<N;i++){
	   for(int j=0;j<N;j++)
		   fout<<rotate[p][i][j]<<" ";
	   fout<<endl;
	}
    fout<<"==================================="<<endl;
  }
  fout<<"--------END END---------"<<endl;
}
*/
bool checkPattern(){
   memset(rotate,false,sizeof(rotate));
   for(int i=0;i<N;i++)
	   for(int j=0;j<N;j++){
		   rotate[0][i][j]=state[S-1][j][N-i-1];
	   }
   for(int i=0;i<N;i++)
	   for(int j=0;j<N;j++){
		   rotate[1][i][j]=rotate[0][j][N-i-1];
	   }
   for(int i=0;i<N;i++)
	   for(int j=0;j<N;j++){
		   rotate[2][i][j]=rotate[1][j][N-i-1];
	   }

   //display();
   for(int k=0;k<S-1;k++){
	   bool found=true;
	   for(int i=0;i<N;i++){
		  if(!found)
			break;
	      for(int j=0;j<N;j++)
			 if(state[k][i][j]!=state[S-1][i][j]){
				 found=false;
				 break;
			 }
	   }
	    if(found)
           return true;
		for(int p=0;p<3;p++){
		  found=true;
		  for(int i=0;i<N;i++){
		    if(!found)
				break;
	        for(int j=0;j<N;j++)
			 if(rotate[p][i][j]!=state[k][i][j]){
				 found=false;
				 break;
			 }
		   }
		   if(found)
			   return true;
		}

   }
   return false;
}
void copyOldState(){
   if(S==0)
	   return;
   for(int i=0;i<N;i++)
	   for(int j=0;j<N;j++)
		   state[S][i][j]=state[S-1][i][j];
}
int main(){
	#ifdef DEBUG
	while(fin>>N){
    #else
	while(cin>>N){
    #endif
        if(N==0)
			break;
		S=0;
		repeated=false;
		memset(state,false,sizeof(state));
		continueSign=false;
		for(int i=0;i<2*N;i++){
		   copyOldState();
           #ifdef DEBUG
           fin>>r>>c>>sign;
           #else
		   cin>>r>>c>>sign;
           #endif
		   if(continueSign)
			   continue;
		   if(sign=='+')
			   add(r-1,c-1);
		   else
		       remove(r-1,c-1);
		   saveState();
		   if(checkPattern()){
			   repeated=true;
			   int playerWon=2-i%2;
			   #ifdef DEBUG
			   fout<<"Player "<<playerWon<<" wins on move "<<i+1<<endl;
			   #else
               cout<<"Player "<<playerWon<<" wins on move "<<i+1<<endl;
			   #endif
			   continueSign=true;
		   }

		}
		if(!repeated)
			#ifdef DEBUG
			fout<<"Draw"<<endl;
		    #else
			cout<<"Draw"<<endl;
		    #endif
	}
	return 0;
}
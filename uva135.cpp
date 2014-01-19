#include <iostream>
#include <fstream>
#include "string.h"
using namespace std;
#ifdef DEBUG
ifstream fin("uva135.in");
ofstream fout("uva135.out");
#endif



int K,a[31][32];
void display(){
   #ifdef DEBUG
   for(int i=0;i<K-1;i++)
	   for(int j=0;j<K;j++)
		   if(j!=K-1)
		    fout<<a[i][j]<<" ";
		   else
		    fout<<a[i][j]<<endl;
   #else
	for(int i=0;i<K-1;i++)
	   for(int j=0;j<K;j++)
		   if(j!=K-1)
		    cout<<a[i][j]<<" ";
		   else
		    cout<<a[i][j]<<endl;
    #endif
}
int main(){
	#ifdef DEBUG
    fin>>K;
	#else
	cin>>K;
	#endif
	while(true){
	   #ifdef DEBUG
	   for(int i=1;i<=K;i++)
		   if(i!=K)
			   fout<<i<<" ";
		   else
			   fout<<i<<endl;
       #else
	   for(int i=1;i<=K;i++)
		   if(i!=K)
			   cout<<i<<" ";
		   else
			   cout<<i<<endl;
	   #endif
          
       for(int i=0;i<K-1;i++)
		   a[i][0]=1;
	   int count=K+1;
	   for(int i=0;i<K-1;i++)
		   for(int j=1;j<K;j++){
              a[i][j]=count;
			  count++;
		   }
	   display();

	   for(int i=2;i<=K;i++){
		   for(int k=0;k<K-1;k++)
		       a[k][0]=i;
           int minus=i-2;
		   count=K+1;
		   int start=0;
		   for(int col=1;col<K;col++){
			   for(int row=0;row<K-1;row++){
                    a[(row+start)%(K-1)][col]=count;
					count++;
			   }
			   start=(start+K-1-minus)%(K-1);
		   }
		   display();
	   }

	   if(cin>>K)
		   cout<<endl;
	   else
		   break;

	}
	return 0;
}

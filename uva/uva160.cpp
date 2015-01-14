#include <iostream>
#include <fstream>
#include <iomanip>
#include "string.h"
using namespace std;
//#decine DEBUG
#ifdef DEBUG
ifstream cin("uva160.in");
ofstream cout("uva160.out");
#endif
int counter,N,n;
int outCount;

int prime[25]={
2,
3,
5,
7,
11,
13,
17,
19,
23,
29,
31,
37,
41,
43,
47,
53,
59,
61,
67,
71,
73,
79,
83,
89,
97};
int pcount[25];

int main(){
	while(cin>>N){
		if(N==0)
			break;
		memset(pcount,0,sizeof(pcount));

		for(int i=2;i<=N;i++){
		  n=i;
		  for(int j=0;j<25&&n>=prime[j];j++){
               counter=0;
			   while(n%prime[j]==0&&n!=1){
                  counter++;
				  n/=prime[j];
			   }
			   pcount[j]+=counter;
		  }
		}
		cout<<setw(3)<<N<<"! =";
		for(int i=0;i<25&&prime[i]<=N;i++){
            
			if((i+1)%15==1&&i!=0)
				cout<<endl<<"      "<<setw(3)<<pcount[i];
			else
                cout<<setw(3)<<pcount[i];
		}
		cout<<endl;

	}



	return 0;
}

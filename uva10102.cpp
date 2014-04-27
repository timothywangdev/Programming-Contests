#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
string m[10000];
int N;
int main(){
	while(cin>>N){
		for(int i=0;i<N;i++)
				cin>>m[i];
		int minimum;
		int rv=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(m[i][j]=='1'){
					minimum=2147483647;
					for(int a=0;a<N;a++)
			          for(int b=0;b<N;b++)
						  if(m[a][b]=='3'){
							  int k=abs(i-a)+abs(j-b);
							  if(k<minimum)
								  minimum=k;
						  }
				    if(minimum>rv)
						rv=minimum;
				}
		cout<<rv<<endl;
	}
	return 0;
}
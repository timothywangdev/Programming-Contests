#include <iostream>
#include <math.h>
using namespace std;
unsigned long long n;
int main(){
	while(cin>>n){
          if(n==0)
			  break;
          unsigned long long k=sqrt((double)n);
		  if(k*k==n)
			  cout<<"yes"<<endl;
		  else
			  cout<<"no"<<endl;
	}
	return 0;
}
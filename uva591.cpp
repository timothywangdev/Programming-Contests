#include <iostream>
#include "stdlib.h"
using namespace std;
int n,height[100],h,t,p,counter=0;
int main(){
	while(cin>>n){
		 counter++;
         if(n==0)
			 break;
		 t=0;
		 for(int i=0;i<n;i++){
			 cin>>height[i];
			 t+=height[i];
		 }
		 t=t/n;
         p=0;
		 for(int i=0;i<n;i++){
		    if(height[i]>t)
              p+=height[i]-t;
		 }
		 cout<<"Set #"<<counter<<endl;
		 cout<<"The minimum number of moves is "<<p<<"."<<endl;
		 if(!cin.eof())
			 cout<<endl;
	}
	return 0;
}
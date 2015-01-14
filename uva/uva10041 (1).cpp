#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int d[30000],n,k;
double abso(double x){
     if(x<0)
		 x=-x;
	 return x;
}
int main(){
    cin>>n;
	for(int i=0;i<n;i++){
       cin>>k;
	   for(int j=0;j<k;j++)
		   cin>>d[j];
	   sort(d,d+k);
	   int m;
	   if(k%2==1){
	     m=d[k/2];
	   }
	   else{
		   double M=(double)(d[k/2-1]+d[k/2])/2;
		   if(abso(floor(M)-M)<abso(ceil(M)-M)){
                m=floor(M);
		   }
		   else{
                m=ceil(M);
		   }
	   }
	   int sum=0;
       for(int i=0;i<k;i++){
          sum+=abs(d[i]-m);
	   }
	   cout<<sum<<endl;
	}
	return 0;
}
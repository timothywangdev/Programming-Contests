#include <iostream>
using namespace std;
int n,a,b;
int main(){
    cin>>n;
	for(int i=0;i<n;i++){
       cin>>a>>b;
	   if(a%2==0)
		   a++;
	   if(b%2==0)
		   b--;
	   cout<<"Case "<<i+1<<": "<<((a+b)*(1+(b-a)/2))/2<<endl;
	}
	return 0;
}
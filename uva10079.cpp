#include <iostream>

using namespace std;

long long f(long long n){
	 return 2+(2+n)*(n-2+1)/2;
}
long long n;
int main(){
	while(cin>>n){
        if(n<0)
			break;
		cout<<f(n)<<endl;
	}
	return 0;
}
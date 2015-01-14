#include <iostream>

using namespace std;
int sum,n,k,b;
int main(){
	while(cin>>n>>k){
	  cout<<n + ((n-1) / (k-1))<<endl;
	}
	return 0;
}
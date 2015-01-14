#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int n,tmp;
int count(int k){
	int sum=0;
	while(k!=0){
		sum+=k&1;
		k=k>>1;
	}
	return sum;
}
int power(int base,int n){
	int sum=1;
	for(int i=0;i<n;i++)
		sum*=base;
	return sum;
}
int toHex(int k){
	ostringstream oss;
	oss<<k;
	string s=oss.str();
	int sum=0;
	for(int i=0;i<s.size();i++){
       sum=sum+(int)(s[i]-'0')*power(16,s.size()-i-1);
	}
	return sum;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		cout<<count(tmp)<<" "<<count(toHex(tmp))<<endl;
	}
	return 0;
}

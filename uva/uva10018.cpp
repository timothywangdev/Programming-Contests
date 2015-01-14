#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int add(unsigned int n){
	ostringstream oss;
	oss<<n;
	string s=oss.str();
	for(unsigned int i=0;i<s.length()/2;i++)
		swap(s[i],s[s.length()-i-1]);
	istringstream iss(s);
	unsigned int nn;
	iss>>nn;
	return n+nn;
}
bool pa(unsigned int n){
	ostringstream oss;
	oss<<n;
	string s=oss.str();
	for(unsigned int i=0;i<s.length()/2;i++)
		if(s[i]!=s[s.length()-i-1])
			return false;
	return true;
}
int main(){
	unsigned int N,n;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>n;
		int count=0;
		while(!pa(n)){
			count++;
			n=add(n);
		}
		cout<<count<<" "<<n<<endl;
	}
}
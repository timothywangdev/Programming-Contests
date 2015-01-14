#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
vector<int> v;
int T,D,K;
string s;
long long power(int k,int n){
	long long rv=1;
	for(int i=0;i<n;i++)
		rv*=k;
	return rv;
}
long long cal(int n){
	long long sum=0;
	for(int i=0;i<v.size();i++){
		sum+=v[i]*power(n,i);
	}
	return sum;
}
long long getResult(){
	int current=0;
	int p=1,n=1;
	while(true){
		current+=p*D;
		if(current>=K)
			return cal(n);
		p++;
		n++;
	}
}
void process(){
	istringstream iss(s);
	int t;
	iss>>t;
	while(iss>>t){
		v.push_back(t);
	}
}
int main(){
	cin>>T;
	for(int t=0;t<T;t++){
		v.clear();
		getline(cin,s);
		getline(cin,s);
		process();
		cin>>D>>K;
		cout<<getResult()<<endl;
	}
	return 0;
}
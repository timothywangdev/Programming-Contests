#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n,k,t;
bool larger(const int &a,const int &b){
	return a>b;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		v.clear();
		for(int j=0;j<k;j++){
			cin>>t;
			v.push_back(t);
		}
		sort(v.begin(),v.end(),larger);
		cout<<"Case "<<i+1<<": "<<v[0]<<endl;
	}

	return 0;
}

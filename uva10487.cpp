#include <iostream>
#include <vector>
#include <stdlib.h> 
using namespace std;

int n,m,t;
vector<int> v;
int main(){
	int counter=0;
	while(cin>>n){
		if(!n)
			break;
		counter++;
		cout<<"Case "<<counter<<":"<<endl;
		v.clear();
		for(int i=0;i<n;i++){
			cin>>t;
			v.push_back(t);
		}
		cin>>m;

		for(int i=0;i<m;i++){
			cin>>t;
			int minimum=2147483647;
			int rv;
			for(int j=0;j<n-1;j++)
				for(int k=j+1;k<n;k++)
					if(abs(v[j]+v[k]-t)<minimum){
						minimum=abs(v[j]+v[k]-t);
						rv=v[j]+v[k];
					}
					cout<<"Closest sum to "<<t<<" is "<<rv<<"."<<endl;
		}
	}
	return 0;
}
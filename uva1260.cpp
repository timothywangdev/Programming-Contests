#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int T,N,t;
int main(){
	cin>>T;
	for(int k=0;k<T;k++){
		cin>>N;
		v.clear();
		for(int i=0;i<N;i++){
			cin>>t;
			v.push_back(t);
		}
		int sum=0;
		for(int i=1;i<N;i++){
			for(int j=0;j<i;j++){
				if(v[j]<=v[i])
					sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
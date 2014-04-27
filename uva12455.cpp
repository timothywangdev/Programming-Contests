#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int T,N,L,t;
bool found;
void search(int index,int sum){
	if(sum==L){
		found=true;
		return;
	}
	if(index==N)
		return;
	search(index+1,sum);
	search(index+1,sum+v[index]);
}
int main(){
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>L>>N;
		v.clear();
		for(int j=0;j<N;j++){
			cin>>t;
			v.push_back(t);
		}
		found=false;
		search(0,0);
		if(found)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
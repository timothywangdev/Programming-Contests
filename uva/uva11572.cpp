#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int,int> m;
vector<int> v;
int T,N,t;
int main(){
	cin>>T;
	for(int k=0;k<T;k++){
		m.clear();
		v.clear();
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>t;
			v.push_back(t);
		}
		int maximum=0,last=0;
		for(int i=0;i<N;i++){
			map<int,int>::iterator it=m.find(v[i]);
			if(it==m.end()||it->second<last){
				m[v[i]]=i;
			}
			else{
				if(i-last>maximum)
					maximum=i-last;
				int p=m[v[i]];
				m[v[i]]=i;
				last=p+1;
			}
		}
		if(N-last>maximum)
					maximum=N-last;
		cout<<maximum<<endl;
	}
	return 0;
}
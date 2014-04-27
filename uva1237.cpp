#include <iostream>
#include <string>

using namespace std;

struct car{
	string name;
	int lo;
	int hi;
};

car v[10000];

int N,Q,T;
int p;
string fi(int p){
	string rv;
	int counter=0;
	for(int i=0;i<N;i++){
		if(v[i].lo<=p&&p<=v[i].hi){
			if(counter==1)
				return "UNDETERMINED";
			rv=v[i].name;
			counter++;
		}
	}
	if(counter==1)
		return rv;
	return "UNDETERMINED";
}
int main(){
	cin>>T;
	for(int t=0;t<T;t++){
		if(t>0)
			cout<<endl;
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>v[i].name>>v[i].lo>>v[i].hi;
		}
		cin>>Q;
		for(int i=0;i<Q;i++){
			cin>>p;
			cout<<fi(p)<<endl;
		}
	}
	return 0;
}
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,int> nameToID;
class UnionJoinSet{
private:
	 int rank[1000000];
	 int p[1000000];
	 int s[1000000];
public:
	void init(int n){
		for(int i=0;i<n;i++){
			rank[i]=0;
			p[i]=i;
			s[i]=1;
		}
	}
	int findSet(int target){
		if(p[target]==target)
          return target;
		else{
			p[target]=findSet(p[target]);
			return p[target];
		}
	}
	bool isSameSet(int a,int b){
		return findSet(a)==findSet(b);
	}
	void unionSet(int a,int b){
		int setA=findSet(a);
		int setB=findSet(b);
		if(rank[setA]>rank[setB]){
			p[setB]=setA;
		}
		else if(rank[setA]<rank[setB]){
			p[setA]=setB;
		}
		else{
			rank[setA]++;
			p[setB]=setA;
		}
		s[setA]+=s[setB];
		s[setB]=s[setA];
	}
	int getSetSize(int a){
		return s[findSet(a)];
	}
};
UnionJoinSet uj;
int T,N,counter;
string a,b;
void addName(string name){
	map<string,int>::iterator it=nameToID.find(name);
	if(it==nameToID.end()){
		counter++;
		nameToID[name]=counter;
	}
}
int main(){
	cin>>T;
	for(int i=0;i<T;i++){
		counter=-1;
		nameToID.clear();
		cin>>N;
		uj.init(2*N);
		for(int j=0;j<N;j++){
			cin>>a>>b;
			addName(a);
			addName(b);
			if(!uj.isSameSet(nameToID[a],nameToID[b]))
			  uj.unionSet(nameToID[a],nameToID[b]);
			cout<<uj.getSetSize(nameToID[a])<<endl;;
		}
	}
	return 0;
}
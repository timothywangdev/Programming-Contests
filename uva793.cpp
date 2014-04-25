#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva793.in");
ofstream fout("uva793.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
class UnionJoinSet{
private:
	vector<int> rank;
	vector<int> p;
public:
	void init(int n){
		rank.clear();
		p.clear();
		for(int i=0;i<n;i++){
			rank.push_back(0);
			p.push_back(i);
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
	}
};
UnionJoinSet uj;
int T,N,a,b,successful,unsuccessful;
char ch;
string s;
void process(string s){
	istringstream iss(s);
	while(iss>>ch>>a>>b){
		if(ch=='c'){
			uj.unionSet(a-1,b-1);
		}
		else{
			if(uj.isSameSet(a-1,b-1))
				successful++;
			else
				unsuccessful++;
		}
	}
}
int main(){
	redirect();
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		uj.init(N);
		successful=unsuccessful=0;
		getline(cin,s);
		while(getline(cin,s)){
			if(s=="")
				break;
			process(s);
		}
		if(i>0)
			cout<<endl;
		cout<<successful<<","<<unsuccessful<<endl;
	}
	return 0;
}
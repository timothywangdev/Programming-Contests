#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
//#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("uva11991.in");
ofstream fout("uva11991.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
int n,m,k,v;
class Pos{
public:
	int value;
	int pos;
};
Pos vv[100000];
map<int,int> startingPos;
map<int,int> endingPos;

bool compare(const Pos &a,const Pos &b){
	return a.value<b.value||(a.value==b.value&&a.pos<b.pos);
}
int fi(int k,int v){
	map<int,int>::iterator it=startingPos.find(v);
	if(it==startingPos.end())
		return 0;
	int start=startingPos[v];
	int ending=endingPos[v];
	k=k+start-1;
	if(k<=ending)
		return vv[k].pos;
	else
		return 0;
}
int main(){
	redirect();
	while(cin>>n>>m){
		startingPos.clear();
		endingPos.clear();
		for(int i=0;i<n;i++){
			cin>>vv[i].value;
			vv[i].pos=i+1;
		}
		sort(vv,vv+n,compare);
		int last=-1;
		for(int i=0;i<n;i++){
			if(vv[i].value!=last){
				endingPos[last]=i-1;
				startingPos[vv[i].value]=i;
				last=vv[i].value;
			}
		}
		endingPos[last]=n-1;
		for(int i=0;i<m;i++){
			cin>>k>>v;
			cout<<fi(k,v)<<endl;
		}
	}
	return 0;
}
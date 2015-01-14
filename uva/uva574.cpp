#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int T,N,v[12],current;
map<string,bool> exist;
vector<int> ans;
bool found;
string toStr(int n){
	ostringstream oss;
	oss<<n;
	return oss.str();
}
void output(){
	found=true;
	string s;
	for(int i=0;i<ans.size();i++){
		if(i>0)
			s=s+"+";
		s=s+toStr(ans[i]);
	}
	map<string,bool>::iterator it=exist.find(s);
	if(it==exist.end()){
		cout<<s<<endl;
		exist[s]=true;
	}
}
void search(int pos){
	if(pos==N){
		if(current==T)
			output();
		return;
	}
	
	current+=v[pos];
	ans.push_back(v[pos]);
	search(pos+1);
	current-=v[pos];
	ans.pop_back();
	search(pos+1);
}
int main(){
	while(cin>>T>>N){
		if(!T&&!N)
			break;
		exist.clear();
		for(int i=0;i<N;i++){
			cin>>v[i];
		}
		current=0;
		found=false;
		cout<<"Sums of "<<T<<":"<<endl;
		search(0);
		if(!found)
			cout<<"NONE"<<endl;
	}
	return 0;

}
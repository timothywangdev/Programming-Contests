#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
string current,target;
stack<char> s;
vector<char> rv;
int currentPos;
void search(int pos){
	if(pos==target.length()){
		cout<<rv[0];
		for(int i=1;i<rv.size();i++)
			cout<<" "<<rv[i];
		cout<<endl;
		return;
	}
	int cp=currentPos;
	for(int i=current.length()-1;i>=cp;i--){
		if(current[i]==target[pos]){
			for(int j=cp;j<=i;j++){
				s.push(current[j]);
				rv.push_back('i');
			}
			rv.push_back('o');
			s.pop();
			currentPos=i+1;
			search(pos+1);
			currentPos=cp;
			s.push(current[i]);
			rv.pop_back();
			for(int j=cp;j<=i;j++){
				s.pop();
				rv.pop_back();
			}
		}
	}
	if(s.size()>0&&s.top()==target[pos]){
		rv.push_back('o');
		char old=s.top();
		s.pop();
		search(pos+1);
		s.push(old);
		rv.pop_back();
	}
}
int main(){
	while(getline(cin,current)&&getline(cin,target)){
		currentPos=0;
		cout<<"["<<endl;
		search(0);
		cout<<"]"<<endl;
	}
	return 0;
}
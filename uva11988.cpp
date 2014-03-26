#include <iostream>
#include <string>
#include <list>
using namespace std;

string s;
list<char> front,ori;
bool f;
int main(){
	while(getline(cin,s)){
		ori.clear();
		for(int i=0;i<s.size();i++){
			if(s[i]=='['){
				if(f){
					ori.splice(ori.begin(),front,front.begin(),front.end());
				}
				f=true;
			}
			else if(s[i]==']'){
				if(f){
					ori.splice(ori.begin(),front,front.begin(),front.end());
				}
				f=false;
			}
			else{
				if(!f)
					ori.push_back(s[i]);
				else
				    front.push_back(s[i]);
			}
		}
		if(f){
			ori.splice(ori.begin(),front,front.begin(),front.end());
		}
		for(list<char>::iterator it=ori.begin();it!=ori.end();it++){
			cout<<*it;
		}
		cout<<endl;
	}
	return 0;
}
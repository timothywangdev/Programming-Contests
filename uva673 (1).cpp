#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva673.in");
ofstream fout("uva673.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}

int n;
string s;
bool check(int h,int t){
	if(h>t)
		return true;
	char c1,c2;


	int last=h,count;
	while(true){
		if(s[last]=='('){
			c1='(';
			c2=')';
		}
		else if(s[last]=='['){
			c1='[';
			c2=']';
		}
		else
			return false;
		count=1;
		for(int i=last+1;i<=t;i++){
			if(s[i]==c1)
				count++;
			else if(s[i]==c2)
				count--;
			if(count==0){
				if(!check(last+1,i-1))
					return false;
				last=i+1;
				break;
			}
		}
		if(count!=0)
			return false;
		if(last>t)
			break;
	}
	return true;
}
class stack{
private: 
		char st[128];	
public:
	 int size;
	 stack(){
		 size=0;
	 }
	 void clear(){
		 size=0;
	 }
	 void push(char ch){
		 st[size]=ch;
		 size++;
	 }
	 bool pop(char expect){
		 if(size==0)
			 return false;
		 size--;
		 if(st[size]!=expect)
			 return false;
		 else
			 return true;
	 }
};
stack ss;
bool rv;
int main(){
	redirect();
	cin>>n;
	getline(cin,s);
	for(int i=0;i<n;i++){
		ss.clear();
		getline(cin,s);
		/*
		if(check(0,s.length()-1))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
			*/
		rv=true;
		for(unsigned int i=0;i<s.length();i++){
			if(s[i]=='('||s[i]=='[')
				ss.push(s[i]);
			else if(s[i]==')'){
				if(!ss.pop('(')){
					rv=false;
					break;
				}
			}
			else if(s[i]==']'){
				if(!ss.pop('[')){
					rv=false;
					break;
				}
			}
		}
		if(ss.size!=0)
			rv=false;
		if(rv)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

	return 0;
}
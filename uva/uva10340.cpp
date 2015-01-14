#include <iostream>
#include <string>
using namespace std;

string s,t;
unsigned int last;
bool findst(unsigned int &last,char ch){
	unsigned int pos=-1;
	for(unsigned int i=last;i<t.length();i++){
		if(t[i]==ch){
            pos=i;
			break;
		}
	}
	if(pos==-1){
		return false;
	}
	else{
        last=pos+1;
		return true;
	} 
}
int main(){
	while(cin>>s>>t){
	   last=0;
	   bool complete=true;
       for(unsigned int i=0;i<s.length();i++)
		   if(!findst(last,s[i])){
              complete=false;
			  break;
		   }
	   if(complete)
		   cout<<"Yes"<<endl;
	   else
		   cout<<"No"<<endl;
	}
	return 0;
}
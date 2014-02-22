#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
using namespace std;

int round;
string sol,seq;
int rv;
int counter[26],strokes;
bool finished(){
	for(int i=0;i<26;i++)
		if(counter[i])
			return false;
	return true;
}
int main(){
	while(cin>>round){
		if(round==-1)
			break;
		cout<<"Round "<<round<<endl;
		getline(cin,sol);
		getline(cin,sol);
		getline(cin,seq);
		memset(counter,0,sizeof(counter));
		strokes=7;
		rv=0;
		for(int i=0;i<sol.length();i++){
			if(!isspace(sol[i]))
				counter[(int)(sol[i]-'a')]++;
		}
		for(int i=0;i<seq.length();i++){
			if(rv)
				break;
			if(counter[seq[i]-'a']>0){
				counter[seq[i]-'a']=0;
				if(finished())
					rv=1;
			}
			else{
                strokes--;
				if(strokes==0){
					rv=2;
				}
			}
		}
		if(!rv)
			rv=3;
		if(rv==1)
			cout<<"You win."<<endl;
		else if(rv==2)
			cout<<"You lose."<<endl;
		else
			cout<<"You chickened out."<<endl;
	}
	return 0;
}
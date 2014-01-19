#include <iostream>
#include <fstream>
#include <string>
#include "ctype.h"
#include "string.h"
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva172.in");
ofstream fout("uva172.out");
#endif
string S,s;

int var[26],oldVar[26];
bool changed[26];
void assign(char assignee,int value){
		var[assignee-'A']=value;
}
bool arithmetic(char ch){
	if(ch=='+'||
		ch=='-'||
		ch=='*'||
		ch=='/'||
		ch=='=')
		return true;
	return false;
}
bool variable(char ch){
	return ('A'<=ch&&ch<='Z');
}
int power(int base,int num){
	int rv=1;
	for(int i=1;i<=num;i++)
		rv=rv*base;
	return rv;
}
int toInt(int start,int end){
	int pos=end-start+1;
	int rv=0;
	for(int i=start;i<=end;i++){
		rv+=power(10,pos-1)*(int)(s[i]-'0');
		pos--;
	}
	return rv;
}
int getValue(int start,int end){
	int sign=1;
	if(s[start]=='_'){
		sign=-1;
		start++;
	}
	if(end-start+1==1){
		if(variable(s[start]))
			return sign*var[s[start]-'A'];
		else
			return sign*toInt(start,end);
	}
	else{
		return sign*toInt(start,end);
	}
}
int caculate(int Lvalue,char oper,int Rvalue){
	switch(oper){
		case '+':return Lvalue+Rvalue;
		case '-':return Lvalue-Rvalue;
		case '*':return Lvalue*Rvalue;
		case '/':return Lvalue/Rvalue;
	}
}


int evulate(int start,int end){
	int pos=start;
	if(s[start]!='('){
		while(!arithmetic(s[pos])&&pos<=end){
			pos++;
		}
		if(pos<=end&&arithmetic(s[pos])){
			pos--;
			if(pos-start+1==1){
				if(variable(s[pos])){
					if(s[pos+1]=='='){
						assign(s[pos],evulate(pos+2,end));
						return var[s[pos]-'A'];
					}
				}
			}
			return caculate(getValue(start,pos),s[pos+1],evulate(pos+2,end));
		}
		else{
			return getValue(start,end);
		}
	}
	else{
		int parenthese=1;
		pos=start;
		while(parenthese!=0){
			pos++;
			if(s[pos]=='(')
				parenthese++;
			if(s[pos]==')')
				parenthese--;
		}
		//if(s[pos]!=')')
		//	fout<<"EXCEPTION NOT ')'"<<endl;
		if(pos+1<=end&&arithmetic(s[pos+1]))
			return caculate(evulate(start,pos),s[pos+1],evulate(pos+2,end));
		else
			return evulate(start+1,pos-1);
	}
}
void display(){
	bool NoChange=true;
	int last=-1;
	for(int i=25;i>=0;i--){
		if(changed[i]){
			last=i;
			break;
		}
	}
	for(int i=0;i<26;i++){
		if(changed[i]){
			NoChange=false;
			#ifdef DEBUG
			if(i!=last){
               fout<<(char)(i+'A')<<" = "<<var[i]<<", ";
			}
			else{
               fout<<(char)(i+'A')<<" = "<<var[i]<<endl;
			}
		}
	}
	if(NoChange)
		fout<<"No Change"<<endl;
	#else
			if(i!=last){
               cout<<(char)(i+'A')<<" = "<<var[i]<<", ";
			}
			else{
               cout<<(char)(i+'A')<<" = "<<var[i]<<endl;
			}
		}
	}
	if(NoChange)
		cout<<"No Change"<<endl;
	#endif
  

}
void process(){
	s="";
	memset(changed,false,sizeof(changed));
	for(unsigned int i=0;i<S.length();i++)
		if(!isspace(S[i]))
			s=s+S[i];
	int tmp=evulate(0,s.length()-1);
	for(int i=0;i<26;i++){
		if(var[i]!=oldVar[i]){
           changed[i]=true;
		   oldVar[i]=var[i];
		}
	}
	display();
}
int main(){
	memset(var,0,sizeof(var));
	memset(oldVar,0,sizeof(oldVar));
#ifdef DEBUG
	while(getline(fin,S)){
#else
	while(getline(cin,S)){
#endif
		if(S[0]=='#')
			break;
		process();
	}
	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "ctype.h"
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva171.in");
ofstream fout("uva171.out");
#endif
string s;
vector<string> item;
int counter=0;
void addItem(int start,int end){
	item.push_back(s.substr(start,end-start+1));

	if(s[start]=='"'&&s[end]=='"'){
	   string singleSpaced;
	   string tmp;
       istringstream iss(item[item.size()-1]);
	   while(iss>>tmp){
           singleSpaced=singleSpaced+tmp+" ";
	   }
	   singleSpaced.erase(singleSpaced.size()-1);
       item[item.size()-1]=singleSpaced;
	}

}
bool when(int start,int end){
	if(start>end)
		return false;
	if(start==end)
		return (item[start]=="FIRST"||item[start]=="SECOND"||item[start]=="THIRD");
	else
		return false;
}
bool how(int start,int end){
	if(start>end)
		return false;
	if(start==end)
		return (item[start]=="GO"||item[start]=="KEEP");
	else
		return (item[start]=="GO"&&when(start+1,end));
}
bool letter(char ch){
	return ('A'<=ch&&ch<='Z');
}
bool sign(int start,int end){
	if(start!=end)
		return false;
	if(item[start].size()<=2)
		return false;
	if(item[start][0]=='"'&&item[start][item[start].length()-1]=='"'){
		if(!isspace(item[start][1])&&!isspace(item[start][item[start].length()-2])){
			for(unsigned int i=1;i<item[start].length()-1;i++){
				if(!(isspace(item[start][i])||letter(item[start][i])||item[start][i]=='.'))
					return false;
				if(item[start][i]=='.')
					if(isspace(item[start][i-1]))
						return false;
			}
		}
		else
			return false;
	}
	return true;
}
bool Where(int start,int end){
	if(start>end)
		return false;
	if(item[start]=="AT"){
		return sign(start+1,end);
	}
	return false;
}
bool directional(int start,int end){
	if(start>end)
		return false;
	int pos=-1;
	for(int i=start;i<=end;i++){
		if(item[i]=="RIGHT"||item[i]=="LEFT"){
			if(pos==-1)
				pos=i;
			else
				return false;
		}
	}
	if(pos==end){
		return how(start,pos-1);
	}
	else{
		return how(start,pos-1)&&Where(pos+1,end);
	}

}
bool cas(int start,int end){
	if(start>end)
		return false;
	if(start==end)
		return item[start]=="CAS";
	else if(end-start+1==3)
		return item[start]=="CHANGE"&&item[start+1]=="AVERAGE"&&item[start+2]=="SPEED";
	else
		return false;
}
bool number(char ch){
	return ('0'<=ch&&ch<='9');
}
bool nnn(int start,int end){
	if(start!=end)
		return false;
	for(unsigned int i=0;i<item[start].length();i++)
		if(!number(item[start][i]))
			return false;
	return true;
}
bool time_keeping(int start,int end){
	if(start>end)
		return false;
	if(end-start+1==2)
		return item[start]=="RECORD"&&item[end]=="TIME";
	else{
		int toPos=-1;
		int KMHpos=-1;
		for(int i=start;i<=end;i++){
			if(item[i]=="TO"){
				if(toPos==-1)
					toPos=i;
				else
					return false;
			}
			if(item[i]=="KMH"){
				if(KMHpos==-1)
					KMHpos=i;
				else
					return false;
			}
		}
		if(KMHpos!=end)
			return false;
		if(toPos==-1||KMHpos==-1)
			return false;
		if(toPos>=KMHpos)
			return false;
		return cas(start,toPos-1)&&nnn(toPos+1,KMHpos-1);
	}
}
bool navigational(int start,int end){
	if(start>end)
		return false;
	int last=-1;
	for(int i=start;i<=end+1;i++){
		if((i==end+1)||(i!=end+1&&item[i]=="AND"&&item[i+1]=="THEN")){
			if(!directional(last+1,i-1))
				return false;
			last=i+1;
		}
	}
	return true;
}
bool instruction(){
	int pos=-1;
	for(unsigned int i=0;i<item.size();i++){
		if(item[i]=="AND"&&(i==item.size()-1||item[i+1]!="THEN")){
			if(pos!=-1)
				return false;
			pos=i;
		}
	}
	if(pos==-1)
		return (navigational(0,item.size()-1)||time_keeping(0,item.size()-1));
	else{
		bool r1=navigational(0,pos-1);
		bool r2=time_keeping(pos+1,item.size()-1);
	    return (navigational(0,pos-1)&&time_keeping(pos+1,item.size()-1));
	}
}
bool process(){
	counter++;
	int last=-2;
	bool finished=true;
	bool speech=false;
	for(unsigned int i=0;i<=s.length();i++){
		if(i!=s.length()&&!isspace(s[i])){
			if(finished){
				last=i;
				finished=false;
				if(s[i]=='"')
					speech=true;
			}
			else if(speech&&s[i]=='"'){
				finished=true;
				speech=false;
				addItem(last,i);
			}
		}
		else{
			if(!speech){
				if(!finished){
					finished=true;
					addItem(last,i-1);
				}
			}
		}
	}
	if(speech)
		return false;
	return instruction();
}
string getSingleSpacedStr(){
   string str;
   for(unsigned int i=0;i<item.size();i++)
	   str=str+" "+item[i];
   return str;
}
void display(bool succeed){
#ifdef DEBUG
	fout<<setw(3)<<counter<<".";
	if(succeed){
        fout<<getSingleSpacedStr()<<endl;
	}
	else{
        fout<<" Trap!"<<endl;
	}
#else
	cout<<setw(3)<<counter<<".";
	if(succeed){
        cout<<getSingleSpacedStr()<<endl;
	}
	else{
        cout<<" Trap!"<<endl;
	}
#endif
}
int main(){
#ifdef DEBUG
	while(getline(fin,s)){
#else
	while(getline(cin,s)){
#endif
		if(s.size()==1&&s[0]=='#')
			break;
		display(process());
		item.clear();
		s.clear();
	}
	return 0;
}
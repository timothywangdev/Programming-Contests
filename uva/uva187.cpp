#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "stdlib.h"
using namespace std;
#ifdef DEBUG
ifstream cin("uva187.in");
ofstream cout("uva187.out");
#endif
struct transaction{
	string s;
	int amount;
};
string s;
vector<string> accounts;
vector<transaction> tran;
int amount;
string space(int num){
	string s;
	for(int i=0;i<num;i++)
		s=s+' ';
	return s;
}
string getException(string tmp){
	return "*** Transaction "+tmp+" is out of balance ***";
}
string getAccount(string num){
	for(unsigned int i=0;i<accounts.size();i++){
		if(accounts[i][0]==num[0]&&
		   accounts[i][1]==num[1]&&
		   accounts[i][2]==num[2])
		   return accounts[i].substr(3,accounts[i].length()-3);
	}
}
string toStr(int n){
	ostringstream oss;
	oss<<n;
	return oss.str();
}
string getStr(int n){
	int integer=n/100;
	int decimal=abs(n-integer*100);
	string inte=toStr(integer);
	string dec=toStr(decimal);
	if(n-integer*100<0&&integer==0)
		inte='-'+inte;
	if(decimal<10)
		dec="0"+dec;
	inte=space(7-inte.length())+inte;
	return inte+'.'+dec;
}

string fill(int num,string t){
	return t+space(30-t.length());
}
string getTran(int index){
	return tran[index].s.substr(3,3)+" "+fill(30,getAccount(tran[index].s.substr(3,3)))+" "+getStr(tran[index].amount);
}
void display(int start,int end,int amount){
	cout<<getException(tran[start].s.substr(0,3))<<endl;
	for(int i=start;i<=end;i++)
		cout<<getTran(i)<<endl;
	cout<<"999 "<<fill(30,"Out of Balance")<<" "<<getStr(-amount)<<endl;
	cout<<endl;
}
int main(){
	while(getline(cin,s)){
		if(s[0]=='0'&&s[1]=='0'&&s[2]=='0')
			break;
		accounts.push_back(s);
	}
	while(true){
		cin>>s>>amount;
		if(s=="000000")
			break;
		transaction tmp={s,amount};
		tran.push_back(tmp);
	}
	int start=0;
	int end=-1;
	int total;
	string tranNum;
	while(true){
		if(end+1>=tran.size())
			break;
		else{
			start=end+1;
			tranNum=tran[end+1].s;
		}
		total=0;
		for(int i=end+1;i<=tran.size();i++){
			if((i==tran.size())||(!(tran[i].s[0]==tranNum[0]&&
				 tran[i].s[1]==tranNum[1]&&
			     tran[i].s[2]==tranNum[2]))){
					 end=i-1;
					 break;
			}
			else{
				total+=tran[i].amount;
			}
		}
		if(total!=0){
			display(start,end,total);
		}
	}
	return 0;
}
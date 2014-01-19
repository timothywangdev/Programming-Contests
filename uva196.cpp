#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "string.h"
using namespace std;
#ifdef DEBUG
ifstream cin("uva196.in");
ofstream cout("uva196.out");
#endif

int N,r,c;
int sheet[999][18278];
bool calculated[999][18278];

class Formula{
public:
	string s;
	int col;
	int row;
	Formula(string s,int row,int col):s(s),row(row),col(col){}
};
vector<Formula*> pending;
string tmp;
void caculate(Formula &f);
int power(int base,int pow){
    int rv=1;
	for(int i=1;i<=pow;i++)
		rv*=base;
	return rv;
}
int nameToInt(string s){
	int sum=0;
    for(int i=0;i<s.length();i++)
		sum+=power(26,i);
	for(int i=0;i<s.length();i++)
		sum+=(int)(s[i]-'A')*power(26,s.length()-i-1);
	return sum-1;
}
int toInt(string num){
    istringstream iss(num);
	int rv;
    iss>>rv;
	return rv;
}
bool number(char ch){
 return '0'<=ch&&ch<='9';
}
int getValue(string &formula,int start,int end){
	string rowStr;
	int col,row;
	for(int i=start;i<=end;i++){
		if(!number(formula[i])){
			rowStr=rowStr+formula[i];
		}
		else{
			col=nameToInt(rowStr);
			row=toInt(formula.substr(i,formula.size()-i))-1;
			break;
		}
	}
	if(!calculated[row][col]){
        caculate(*pending[sheet[row][col]]);
	}
	return sheet[row][col];
}
int getResult(string &formula){
	int sum=0;
	int last=0;
	for(unsigned int i=1;i<=formula.length();i++){
		if(formula[i]=='+'||i==formula.length()){
			sum+=getValue(formula,last+1,i-1);
			last=i;
		}
	}
	return sum;
}
void caculate(Formula &f){
	if(calculated[f.row][f.col])
		return;
	sheet[f.row][f.col]=getResult(f.s);
	calculated[f.row][f.col]=true;
}
void process(){
	for(unsigned int i=0;i<pending.size();i++)
		caculate(*pending[i]);
	for(int row=0;row<r;row++){
		for(int col=0;col<c;col++){
			cout<<sheet[row][col];
			if(col!=c-1)
				cout<<" ";
		}
		cout<<endl;
	}
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>c>>r;
		pending.clear();
		memset(calculated,false,sizeof(calculated));
		for(int row=0;row<r;row++)
			for(int col=0;col<c;col++){
				cin>>tmp;
				if(tmp[0]=='='){
					pending.push_back(new Formula(tmp,row,col));
					sheet[row][col]=pending.size()-1;
				}
				else{
					calculated[row][col]=true;
					sheet[row][col]=toInt(tmp);
				}
			}
			process();  
	}
	return 0;
}
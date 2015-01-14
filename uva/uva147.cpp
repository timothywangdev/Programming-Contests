#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "string.h"
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva147.in");
ofstream fout("uva147.out");
#endif
long long  f[30001][11];
long long curr[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
double tmp;
string s;
string space(int n){
  string s="";
  for(int i=0;i<n;i++)
	  s=s+' ';
  return s;
}
int toInt(string s){
	istringstream convert(s);
	int rv;
	convert>>rv;
	return rv;
}
int main(){
	memset(f,0,sizeof(f));
	for(int i=0;i<11;i++)
			f[0][i]=1;
	int last=1;
	while(cin>>s){
		tmp=atof(s.c_str());
		if(s=="0.00")
			break;
		
		int integer=toInt(s.substr(0,s.length()-3))*100+toInt(s.substr(s.length()-2,2));
		if(integer>=last){
		  for(int i=last;i<=integer;i++)
			for(int j=0;j<11;j++){
				for(int k=0;k<=j;k++)
				  if(i>=curr[k])
					f[i][j]+=f[i-curr[k]][k];
			}
		  last=integer+1;
		}
		cout<<space(6-s.length())<<s<<setw(17)<<f[integer][10]<<endl;
	}
	return 0;
}
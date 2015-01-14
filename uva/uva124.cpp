#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>

#include "string.h"
using namespace std;
//ifstream fin("uva124.in");
//ofstream cout("uva124.out");

map<int,int> toVar;
istringstream iss;
bool ignore[26],con[26][26];
string tmp;
char ch,a,b;
int var[20];
int N;
void display(string s){
     cout<<s<<endl;
}
void searchOrder(int pos,string s,int remaining){
	if(pos>N){
		display(s);
		return;
	}
	if(remaining<(N-pos+1))
		return;
	int n;
	int change[20];
	memset(change,0,sizeof(change));

	for(int i=0;i<N;i++)
		if(!ignore[var[i]]){
			ignore[var[i]]=true;
			n=0;
			for(int j=0;j<N;j++)
				if(con[var[j]][var[i]]&&!ignore[var[j]]){
					ignore[var[j]]=true;
					change[n]=j;
					n++;
				}
            searchOrder(pos+1,s+(char)('a'+var[i]),remaining-n-1);
			for(int j=0;j<n;j++)
              ignore[var[change[j]]]=false;

			ignore[var[i]]=false;
		}
}
int main(){
	while(getline(cin,tmp)){
		N=0;
		memset(ignore,false,sizeof(ignore));
		memset(con,false,sizeof(con));
		if(!('a'<=tmp[0]&&tmp[0]<='z'))
			break;
		iss.str(tmp);
		while(iss>>ch){
			var[N]=(int)(ch-'a');
			N++;
		}
		sort(var,var+N);
		for(int i=0;i<N;i++)
			toVar[var[i]]=i;

		iss.clear();
		getline(cin,tmp);
		iss.str(tmp);
		while(iss>>a>>b){
			con[var[toVar[(int)(a-'a')]]][var[toVar[(int)(b-'a')]]]=true;
		}
		
		for(int k=0;k<26;k++)
			for(int i=0;i<26;i++)
				for(int j=0;j<26;j++)
					if(con[i][k]&&con[k][j])
						con[i][j]=true;

		searchOrder(1,"",N);
		toVar.clear();
		iss.clear();
		ch=cin.peek();
		if('a'<=ch&&ch<='z')
		 cout<<endl;
	}
}
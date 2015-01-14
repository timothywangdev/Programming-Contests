#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "string.h"
#include <vector>
#include <map>
//#define DEBUG
using namespace std;
#ifdef DEBUG
ifstream fin("uva146.in");
ofstream fout("uva146.out");
#endif

string s;
int rv[100];
int used[100];
vector<int> canuse;
map<int,int> toCanuse;

int N;
bool found,firstTime[100];
void display(){
	   for(int i=0;i<s.size();i++)
		   cout<<(char)('a'+rv[i]);
	   cout<<endl;
}
void process(int current){
	
	if(found)
		return;

	if(current==N){
		if(!firstTime[current]){
          found=true; 
		  display();
		}
		else
		  firstTime[current]=false;
		return;
	}
	int nextch=toCanuse[rv[current]];
	if(firstTime[current]){
		firstTime[current]=false;
		goto next;
	}

	do{
		nextch++;
		if((nextch>=canuse.size()))
			break;
		if(used[canuse[nextch]]!=0){
           used[canuse[nextch]]--;
		   rv[current]=canuse[nextch];
		   next:
		   process(current+1);
		   used[canuse[nextch]]++;
		}
	}while((nextch<canuse.size()));
	rv[current]=-1;
}


int main(){

	while(cin>>s){
		if(s[0]=='#')
			break;
		N=s.size();
		memset(used,0,sizeof(used));
		memset(rv,0,sizeof(rv));
		memset(firstTime,true,sizeof(firstTime));
		found=false;
		canuse.clear();
		for(unsigned int i=0;i<s.size();i++){
		   if(used[s[i]-'a']==0)
			   canuse.push_back((int)(s[i]-'a'));
		   used[s[i]-'a']++;
		   rv[i]=(int)(s[i]-'a');
		}
		memset(used,0,sizeof(used));
		sort(canuse.begin(),canuse.end());
		for(unsigned int i=0;i<canuse.size();i++)
			toCanuse[canuse[i]]=i;
		toCanuse[-1]=-1;
		process(0);
		if(!found)
		 cout<<"No Successor"<<endl;
	}

	return 0;
}


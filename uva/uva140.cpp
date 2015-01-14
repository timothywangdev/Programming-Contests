//#define DEBUG
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include "string.h"
#include <stdlib.h>  
#define MAXIMUM 100;
using namespace std;
#ifdef DEBUG
ifstream fin("uva140.in");
ofstream fout("uva140.out");
#endif
bool adj[260][260],exist[260];
int N,rv[80],rvCopy[80],bandwidth;
string s;
bool used[260];
int max(int a,int b){
	return (a>b)?a:b;
}
void addNode(int start,int end){
	if(!exist[(int)(s[start]-'A')]){
			  N++;
			  exist[(int)(s[start]-'A')]=true;
	}
	for(int i=start+2;i<=end;i++){
		  if(s[start]==s[i])
			  continue;
		  adj[(int)(s[start]-'A')][(int)(s[i]-'A')]=adj[(int)(s[i]-'A')][(int)(s[start]-'A')]=true;
		  if(!exist[(int)(s[i]-'A')])
			  N++;
		  exist[(int)(s[start]-'A')]=exist[(int)(s[i]-'A')]=true;
	}
}
void createGraph(){
	int pos=s.find(';'),last=-1;
	if(pos==string::npos)
		   addNode(last+1,s.length()-1);
	while(pos!=string::npos){
       addNode(last+1,pos-1);
	   last=pos;
	   pos=s.find(';',pos+1);
	   if(pos==string::npos)
		   addNode(last+1,s.length()-1);
	}
}
void updateResult(){
     int index[80],individual,total=0;
	 for(int i=0;i<N;i++)
		 index[rv[i]]=i;
	 for(int i=0;i<N;i++){
		 individual=0;
		 for(int j=0;j<26;j++)
			 if(adj[rv[i]][j])
               individual=max(individual,abs(index[rv[i]]-index[j]));
         total=max(total,individual);
	 }
	 if(total<bandwidth){
	    bandwidth=total;
        for(int i=0;i<N;i++)
			rvCopy[i]=rv[i];
	 }
}
void search(int current){
   if(current==N){
      updateResult();
	  return;
   }
   for(int i=0;i<26;i++)
	   if(!used[i]&&exist[i]){
           used[i]=true;
		   rv[current]=i;
		   search(current+1);
		   used[i]=false;
	   }
}
void display(){
   #ifdef DEBUG
   for(int i=0;i<N;i++)
		   fout<<(char)('A'+rvCopy[i])<<" ";

   fout<<"-> "<<bandwidth<<endl;
   #else
   for(int i=0;i<N;i++)
		   cout<<(char)('A'+rvCopy[i])<<" ";

   cout<<"-> "<<bandwidth<<endl;
   #endif

}
int main(){
#ifdef DEBUG
	while(getline(fin,s)){
#else
    while(getline(cin,s)){
#endif
		if(s[0]=='#')
			break;
		N=0;
		bandwidth=MAXIMUM;
		memset(used,false,sizeof(used));
		memset(exist,false,sizeof(exist));
		memset(adj,false,sizeof(adj));
        createGraph();
		if(N>1)
         search(0);
		else{
		 int target;
		 for(int i=0;i<26;i++)
			 if(exist[i])
			 {
				 target=i;
				 break;
			 }
		 rvCopy[0]=target;
		 bandwidth=0;
		}
		display();
	}
	return 0;
}
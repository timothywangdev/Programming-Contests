#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
#ifdef DEBUG
ifstream cin("uva10004.in");
ofstream cout("uva10004.out");
#endif
bool m[200][200],rv;
int c[200];
int n,l,a,b;
bool check(int index){
    for(int i=0;i<n;i++)
		if(m[i][index]&&c[i]==c[index])
			return false;
	return true;
}
void search(int index){
	if(rv)
		return;
	if(index>=n){
		rv=true;
		return;
	}
	if(c[index]==0){
       c[index]=1;
	   if(check(index)){
          search(index+1);
	   }
	   c[index]=2;
       if(check(index)){
          search(index+1);
	   }
	}
	else
	   search(index+1);
	c[index]=0;
}
int main(){
	while(cin>>n){
        if(n==0)
			break;
		cin>>l;
		memset(m,false,sizeof(m));
        memset(c,0,sizeof(c));
		rv=false;
		for(int i=0;i<l;i++){
           cin>>a>>b;
		   m[a][b]=m[b][a]=true;
		}
		search(0);
		if(rv)
			cout<<"BICOLORABLE."<<endl;
		else
			cout<<"NOT BICOLORABLE."<<endl;
	}
	return 0;
}
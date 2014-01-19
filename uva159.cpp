#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "string.h"
using namespace std;
//#decine DEBUG
#ifdef DEBUG
ifstream cin("uva159.in");
ofstream cout("uva159.out");
#endif

string h1,v1,h2,v2;



struct crossResult{

	// 0: H 1:V
	int pos[2];
};
string s;
istringstream iss;
int w[50];
bool existV[26];
char rv[500][500];
crossResult makeCross(string h,string v){
	
	memset(existV,false,sizeof(existV));
	crossResult result;
	result.pos[0]=result.pos[1]=-1;
	for(unsigned int i=0;i<v.length();i++)
		existV[v[i]-'A']=true;
	for(unsigned int i=0;i<h.length();i++){
		if(existV[h[i]-'A']){
			result.pos[0]=i;
			break;
		}
	}
	if(result.pos[0]!=-1){
       for(unsigned int i=0;i<v.length();i++)
		   if(v[i]==h[result.pos[0]]){
               result.pos[1]=i;
			   break;
		   } 
	}
	return result;
}
int cindFurthest(int i,int W){
    for(int j=W-1;j>=0;j--)
		if('A'<=rv[i][j]&&rv[i][j]<='Z')
			return j+1;
}
void display(crossResult &r1,crossResult &r2){
    
	memset(rv,0,sizeof(rv));
	memset(w,0,sizeof(w));
	int maxH,minH,underMaxH;
	if(r1.pos[1]>r2.pos[1]){
        maxH=r1.pos[1];
		minH=r2.pos[1];
	}
	else{
        maxH=r2.pos[1];
		minH=r1.pos[1];
	}
	underMaxH=max(v1.length()-r1.pos[1]-1,v2.length()-r2.pos[1]-1);

	// Draw first H
	for(unsigned int i=0;i<h1.length();i++)
		rv[maxH][i]=h1[i];

	// Draw first V
    for(unsigned int i=0;i<v1.length();i++)
		rv[maxH-r1.pos[1]+i][r1.pos[0]]=v1[i];

	// Draw second H
	for(unsigned int i=0;i<h2.length();i++)
		rv[maxH][h1.length()+3+i]=h2[i];

	// Draw second V
    for(unsigned int i=0;i<v2.length();i++)
		rv[maxH-r2.pos[1]+i][h1.length()+3+r2.pos[0]]=v2[i];

	// Draw grid
	int W=h1.length()+h2.length()+3;
	int H=maxH+1+underMaxH;
    for(int i=0;i<H;i++)
		w[i]=cindFurthest(i,W);
	for(int i=0;i<H;i++){
		for(int j=0;j<w[i];j++){
			if(rv[i][j]!=0)
			 cout<<rv[i][j];
			else
			 cout<<' ';
		}
		cout<<endl;
	}
	
}
void process(){
	crossResult r1,r2;
	r1=makeCross(h1,v1);
	r2=makeCross(h2,v2);
	if(r1.pos[0]==-1||r2.pos[0]==-1)
		cout<<"Unable to make two crosses"<<endl;
	else
		display(r1,r2);
}
int main(){
	
    char ch;
	while(getline(cin,s)){
		iss.str(s);
		if(s[0]=='#')
			break;
		iss>>h1>>v1>>h2>>v2;
		process();
		iss.clear();
		ch=cin.peek();
		if(ch!='#')
			cout<<endl;
	}
	return 0;
}
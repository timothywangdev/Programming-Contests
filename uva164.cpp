#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "string.h"
#include "math.h"
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva164.in");
ofstream fout("uva164.out");
#endif
string a,b,s;
int f[21][21];
int path[21][21][2];
string toString(int n){
	ostringstream oss;
	oss<<n;
	return oss.str();
}
string getNum(int n){
	if(n<10)
		return "0"+toString(n);
	else
		return toString(n);
}
void addDeletion(int i){
	s=s+"D"+a[i-1]+getNum(i);
}
void addInsertion(int i){
	s=s+"I"+b[i-1]+getNum(i);
}
void addSub(int i){
	s=s+"C"+b[i-1]+getNum(i);
}
void decrease(int i){
   int first=4*i-2,
	   second=4*i-1;
   if(s[first]=='1'&&s[second]=='0'){
        s[first]='0';
		s[second]='9';
   }
   else if(s[first]=='0'){
       s[second]=(char)((s[second]-'0'-1)+'0');
   }
   else{
	   if(s[first]=='2'&&s[second]=='0'){
          s[first]='1';
		  s[second]='9';
	   }
	   else{
          s[second]=(char)((s[second]-'0'-1)+'0');
	   }
   }
}
void increase(int i){
   int first=4*i-2,
	   second=4*i-1;
   if(s[first]=='0'&&s[second]=='9'){
        s[first]='1';
		s[second]='0';
   }
   else if(s[first]=='0'){
       s[second]=(char)((s[second]-'0'+1)+'0');
   }
   else{
	   if(s[first]=='1'&&s[second]=='9'){
          s[first]='2';
		  s[second]='0';
	   }
	   else{
          s[second]=(char)((s[second]-'0'+1)+'0');
	   }
   }
}
void process(){
	path[0][0][0]=-1;
	path[0][0][1]=-1;
	for(int i=0;i<=(int)a.length();i++){
		for(int j=0;j<=(int)b.length();j++){
			if(i==0&&j!=0){
				f[i][j]=j;
				path[i][j][0]=i;
				path[i][j][1]=j-1;
			}
			else if(j==0&&i!=0){
				f[i][j]=i;
				path[i][j][0]=i-1;
				path[i][j][1]=j;
			}
			else if(i!=0&&j!=0){
				f[i][j]=f[i-1][j]+1;
				path[i][j][0]=i-1;
				path[i][j][1]=j;
				if(f[i][j-1]+1<f[i][j]){
					f[i][j]=f[i][j-1]+1;
					path[i][j][0]=i;
					path[i][j][1]=j-1;
				}
				if(f[i-1][j-1]+(a[i-1]!=b[j-1])<f[i][j]){
					f[i][j]=f[i-1][j-1]+(a[i-1]!=b[j-1]);
					path[i][j][0]=i-1;
					path[i][j][1]=j-1;
				}
			}
		}
	}
	s="";
	int pi=(int)a.length(),
		pj=(int)b.length(),
		pa,pb;
	//fout<<f[pi][pj]<<endl;
	while(!(pi==0&&pj==0)){
		pa=path[pi][pj][0];
		pb=path[pi][pj][1];
		if(pa==-1&&pb==-1)
			break;
		if((pa==pi-1&&pb==pj)){
			 addDeletion(pi);
		}
		else if((pa==pi&&pb==pj-1)){
			 addInsertion(pj);
		}
		else if(a[pi-1]!=b[pj-1]){
			addSub(pj);
		}
		pi=pa;
		pj=pb;
	}
	for(int i=f[a.length()][b.length()];i>=2;i--){
		if(s[4*i-4]=='D'){
		  for(int j=i-1;j>=1;j--)
			  if(s[4*j-4]=='D')
				 decrease(j);
		}
		else if(s[4*i-4]=='I'){
           for(int j=i-1;j>=1;j--)
			  if(s[4*j-4]=='D')
				 increase(j);
		}
	}

	for(int i=f[a.length()][b.length()];i>=1;i--){
        cout<<s[4*i-4]<<s[4*i-3]<<s[4*i-2]<<s[4*i-1];
	}
	//fout<<s;
	cout<<"E"<<endl;

}
int main(){
	while(cin>>a){
		if(a[0]=='#')
			break;
		memset(f,0,sizeof(f));
		memset(path,0,sizeof(path));
		cin>>b;
		process();
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;


string s[8];
int w=0,b=0;
int eva[26];
int main(){
   memset(eva,0,sizeof(eva));
   eva['q'-'a']=9;
   eva['r'-'a']=5;
   eva['b'-'a']=3;
   eva['n'-'a']=3;
   eva['p'-'a']=1;
   for(int i=0;i<8;i++){
      cin>>s[i];
      for(int j=0;j<8;j++){
	 if(s[i][j]=='.')continue;
	 if('a'<=s[i][j]&&s[i][j]<='z'){
	    b+=eva[s[i][j]-'a'];
	 }
	 else{
	    w+=eva[s[i][j]-'A'];
	 }
      }
   }
   if(w>b){
      cout<<"White"<<endl;
   }
   else if(w<b){
      cout<<"Black"<<endl;
   }
   else{
      cout<<"Draw"<<endl;
   }
   return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

string s;
int f[100][100],repeat[100][100];
int main(){
  while(cin>>s){
    if(s[0]=='*')break;
    memset(repeat,0,sizeof(repeat));
    for(int i=0;i<s.length();i++){
      for(int len=1;len<=s.length()-i;len++){
	string sub=s.substr(i,len);
	for(int k=i;k+sub.length()-1<s.length();k+=sub.length()){
	  if(s.substr(k,sub.length())==sub){
	    repeat[i][k+sub.length()-1]=max(repeat[i][k+sub.length()-1],(int)((k-i)/sub.length())+1);
	  }
	  else{
	    break;
	  }
	}
      }
    }
    for(int len=1;len<=s.length();len++){
      for(int i=0;i+len-1<s.length();i++){
	int j=i+len-1;
	int n=repeat[i][j];
	int l=len/n;
	if(l<len){
	  f[i][j]=f[i][i+l-1];
	}
	else{
	  f[i][j]=j-i+1;
	}
	for(int k=i;k<=j-1;k++){
	  f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
	}
      }
    }
    cout<<f[0][s.length()-1]<<endl;
  }
  return 0;
}

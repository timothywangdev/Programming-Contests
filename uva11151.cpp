#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int f[1000][1000];
int T;
string s;
int main(){
  cin>>T;
  getline(cin,s);
  for(int t=0;t<T;t++){
    getline(cin,s);
    memset(f,0,sizeof(f));
    for(int len=1;len<=s.length();len++){
      for(int i=0;i+len-1<s.length();i++){
	int j=i+len-1;
	if(len==1){
	  f[i][j]=1;
	  continue;
	}
	else if(len==2){
	  if(s[i]==s[j]){
	    f[i][j]=2;
	  }
	  else{
	    f[i][j]=1;
	  }
	  continue;
	}
	if(s[i]==s[j]){
	  f[i][j]=f[i+1][j-1]+2;
	}
	else{
	  f[i][j]=0;
	}
	f[i][j]=max(f[i][j],max(f[i+1][j],f[i][j-1]));
      }
    }
      cout<<f[0][s.length()-1]<<endl;
  }
  return 0;
}

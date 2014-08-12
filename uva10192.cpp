#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int f[101][101];
string s[2];
int counter=0;
int main(){
  while(getline(cin,s[0])){
    if(s[0].size()>=1&&s[0][0]=='#')break;
    counter++;
    getline(cin,s[1]);
    memset(f,0,sizeof(f));
    for(int i=1;i<=s[0].length();i++){
      for(int j=1;j<=s[1].length();j++){
	f[i][j]=-1;
	if(s[0][i-1]==s[1][j-1]){
	  f[i][j]=f[i-1][j-1]+1;
	}
	f[i][j]=max(f[i][j],max(f[i-1][j],f[i][j-1]));
      }
    }
    cout<<"Case #"<<counter<<": "<<"you can visit at most "<<f[s[0].length()][s[1].length()]<<" cities."<<endl;
  }
  return 0;
}

#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

string s[2];
int counter[2][26];
int main(){
  while(getline(cin,s[0])){
    getline(cin,s[1]);
    memset(counter,0,sizeof(counter));
    for(int i=0;i<2;i++){
      for(int j=0;j<s[i].size();j++){
	counter[i][s[i][j]-'a']++;
      }
    }
    string rv;
    for(int i=0;i<26;i++){
      for(int j=0;j<min(counter[0][i],counter[1][i]);j++){
	rv=rv+(char)('a'+i);
      }
    }
    cout<<rv<<endl;
  }
  return 0;
}

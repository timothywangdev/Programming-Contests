#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;
typedef long long LL;

LL f[201];
int T;
string s;
LL toLL(string s){
  LL rv;
  istringstream iss(s);
  iss>>rv;
  return rv;
}
int main(){
  cin>>T;
  getline(cin,s);
  for(int t=0;t<T;t++){
    getline(cin,s);
    f[0]=0;
    for(int i=1;i<=s.length();i++){
      f[i]=0;
      for(int len=1;len<=10;len++){
	if(i-len<0)break;
	string sub=s.substr(i-len,len);
	LL n=toLL(sub);
	if(n>2147483647)break;
	f[i]=max(f[i],f[i-len]+n);
      }
    }
    cout<<f[s.length()]<<endl;
  }
  return 0;
}

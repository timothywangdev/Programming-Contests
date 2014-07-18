#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <functional>
using namespace std;

string s1,s2,s;

long long toNum(string s){
  long long rv;
  istringstream iss(s);
  iss>>rv;
  return rv;
}
string toStr(long long n){
  ostringstream oss;
  oss<<n;
  return oss.str();
}
long long N,index;
int main(){
  while(cin>>N){
    s=toStr(N);
    char small=s[0];
    index=0;
    for(int i=0;i<s.size();i++){
      if(s[i]!='0'){
	if(small>s[i]){
	  small=s[i];
	  index=i;
	}
      }
    }
    s1=s;
    s2="";
    if(s.size()>=2){
      if(index<s.size()-1){
	s2=s.substr(0,index)+s.substr(index+1,s.size()-index);
      }
      else{
	s2=s.substr(0,index);
      }
    }
    sort(s1.begin(),s1.end(),greater<int>());
    sort(s2.begin(),s2.end());
    s2=small+s2;
    long long n1=toNum(s1),n2=toNum(s2);
    n1=n1-n2;
    cout<<s1<<" - "<<s2<<" = "<<n1<<" = "<<"9 * "<<n1/9<<endl;
  }
  return 0;
}

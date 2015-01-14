#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string s;
int toInt(string s){
  int rv;
  istringstream iss(s);
  iss>>rv;
  return rv;
}
int main(){
  int counter=0;
  while(cin>>s){
    int a,b;
    for(int i=0;i<s.size();i++){
      if(s[i]=='+'||s[i]=='-'){
	a=i;
      }
      if(s[i]=='='){
	b=i;
      }
    }
    string s1=s.substr(0,a);
    string s2=s.substr(a+1,b-a-1);
    string s3=s.substr(b+1,s.length()-b-1);
    if(s3=="?")continue;
    int aa=toInt(s1);
    int bb=toInt(s2);
    int cc=toInt(s3);
    if(s[a]=='+'){
      counter+=(aa+bb==cc);
    }
    if(s[a]=='-'){
      counter+=(aa-bb==cc);
    }
  }
  cout<<counter<<endl;
  return 0;
}

#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

map<string,bool> exist;

int toInt(string s){
  int rv;
  istringstream iss(s);
  iss>>rv;
  return rv;
}
string toString(int n){
  ostringstream oss;
  oss<<n;
  string s=oss.str();
  int k=8-s.length();
  for(int i=0;i<k;i++){
    s='0'+s;
  }
  return s;
}
int process(string s){
  exist.clear();
  int counter=0;
  while(true){
    if(exist.find(s)!=exist.end()){
      return counter;
    }
    exist[s]=true;
    counter++;
    int k=toInt(s);
    k*=k;
    string tmp=toString(k);
    s=tmp.substr(2,4);
  }
}
string s;
int main(){
  while(cin>>s){
    if(s=="0")break;
    cout<<process(s)<<endl;
  }
  return 0;
}

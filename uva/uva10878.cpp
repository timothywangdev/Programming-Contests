#include <string>
#include <map>
#include <iostream>
using namespace std;

string s;

map<string,char> toChar;

int current=0;

int power(int base,int k){
  int rv=1;
  for(int i=0;i<k;i++){
    rv*=base;
  }
  return rv;
}
int toInt(string s){
  int sum=0;
  for(int i=s.length()-1;i>=0;i--){
    sum+=(s[i]=='1')?power(2,s.length()-i-1):0;
  }
  return sum;
}
void decode(string s){
  if(s[0]!='|')return;
  s=s.substr(2,s.length()-3);
  string bi="";
  for(int i=0;i<s.length();i++){
    if(s[i]=='o'){
      bi=bi+'1';
    }
    else if(s[i]!='.'){
      bi=bi+'0';
    }
  }
  // cout<<bi<<endl;
  cout<<(char)toInt(bi);
}

int main(){
  bool first=true;
  while(getline(cin,s)){
    if(s[0]=='_'){
      if(first){
	first=false;
      }
      else{
	break;
      }
    }
    decode(s);
  }
  return 0;
}

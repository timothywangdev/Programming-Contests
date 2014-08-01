#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string s;

bool isInt(string s){
  bool integer=true;
  if(s.length()==0)return false;
  if(s[0]=='-'||s[0]=='+'){
    s=s.substr(1,s.length()-1);
  }
  for(int i=0;i<s.size();i++){
    if(!('0'<=s[i]&&s[i]<='9')){
      return false;
    }
  }
  return true;
}
bool check_exp(string s){
  return isInt(s);
}
bool check_const(string s,bool dot){
  int index=-1;
  for(int i=0;i<s.size();i++){
    if(s[i]=='.'){
      index=i;
      break;
    }
  }
  if(index==-1){
    if(dot)return false;
    return isInt(s);
  }
  else{
    return isInt(s.substr(0,index))&&isInt(s.substr(index+1,s.length()-index-1));
  }
}

bool check_token(string s){
  int index=-1;
  for(int i=0;i<s.size();i++){
    if(s[i]=='e'||s[i]=='E'){
      index=i;
      break;
    }
  }
  if(index==-1){
    return check_const(s,true);
  }
  else{
    // cout<<check_const(s.substr(0,index))<<endl;
    //cout<<check_exp(s.substr(index+1,s.length()-index-1))<<endl;
    return check_const(s.substr(0,index),false)&&check_exp(s.substr(index+1,s.length()-index-1));
  }
}
void check(string s){
  string token;
  istringstream iss(s);
  int counter=0;
  int index=0;
  for(int i=0;i<s.length();i++){
    if(s[i]!=' '){
      index=i;
      break;
    }
  }
  s=s.substr(index,s.length()-index);
  while(iss>>token){
    counter++;
  }
  if(counter!=1){
    cout<<s<<" is illegal."<<endl;
    return;
  }
  if(check_token(token)){
    cout<<token<<" is legal."<<endl;
  }
  else{
    cout<<token<<" is illegal."<<endl;
  }
}
int main(){
  while(getline(cin,s)){
    if(s[0]=='*')break;
    check(s);
  }
  return 0;
}

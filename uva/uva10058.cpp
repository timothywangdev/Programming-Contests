/*
Stupidest problem ever!!!!!!!!!!!!
DO NOT COPY-AND-PASTE OUTPUT STRING FROM UVA, TYPE THEM BY YOURSELF!!!!
 */

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

vector<string> v;
string s,token;

bool isArticle(string s){
  return s=="a"||s=="the";
}
bool isNoun(string s){
  return s=="tom"||s=="jerry"||s=="goofy"||s=="mickey"||s=="jimmy"||s=="dog"||s=="cat"||s=="mouse";
}
bool allS(string s){
  for(int i=0;i<s.size();i++){
    if(s[i]!='s')return false;
  }
  return true;
}
bool isVerb(string s){
  int index=-1;
  for(int i=0;i<s.size();i++){
    if(s[i]=='s'){
      index=i;
      break;
    }
  }
  if(index==-1){
    return s=="hate"||s=="love"||s=="know"||s=="like";
  }
  string t=s.substr(0,index);
  return (t=="hate"||t=="love"||t=="know"||t=="like")&&allS(s.substr(index,s.length()-index));
}
bool actor(int start,int end){
  if(start>end)return false;
  if(start==end){
    return isNoun(v[start]);
  }
  else{
    if(end==start+1){
      return isArticle(v[start])&&isNoun(v[end]);
    }
  }
  return false;
}
bool active_list(int start,int end){
  if(start>end)return false;
  int index=-1;
  for(int i=end;i>=start;i--){
    if(v[i]=="and"){
      index=i;
      break;
    }
  }
  if(index==-1){
    return actor(start,end);
  }
  else{
    return active_list(start,index-1)&&actor(index+1,end);
  }
}
bool action(int start,int end){
  if(start>end)return false;
  int index=-1;
  for(int i=start;i<=end;i++){
    if(isVerb(v[i])){
      index=i;
      break;
    }
  }
  if(index==-1)return false;
  return active_list(start,index-1)&&active_list(index+1,end);
}
bool statement(int start,int end){
  if(start>end)return false;
  int index=-1;
  for(int i=end;i>=start;i--){
    if(v[i]==","){
      index=i;
      break;
    }
  }
  if(index==-1){
    return action(start,end);
  }
  else{
    return  statement(start,index-1)&&action(index+1,end);
  }
}
int main(){
  while(getline(cin,s)){
    v.clear();
    istringstream iss(s);
    while(iss>>token){
       int pre=-1;
       /*
       for(int i=0;i<=token.size();i++){
	 if(token[i]==','||i==token.size()){
	   if(i-pre-1!=0){
	     v.push_back(token.substr(pre+1,i-pre-1));
	   }
	   if(i!=token.size()){
	     v.push_back(",");
	   }
	   pre=i;
	 }
       }
       */
       v.push_back(token);
    }
    if(statement(0,v.size()-1)){
      cout<<"YES I WILL"<<endl;
    }
    else{
      cout<<"NO I WON'T"<<endl;
    }
  }
  return 0;
}

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <stdio.h>
using namespace std;

string s,de,word;
map<string,bool> exist;
int maximum;
string decode(string ori,int shift){
  char ch;
  string rv;
  for(int i=0;i<ori.size();i++){
    int k=(ori[i]!=' ')?(int)(ori[i]-'A'+1):0;
    k=(k+shift)%27;
    if(k==0){
      ch=' ';
    }
    else{
      ch=(char)('A'+k-1);
    }
    rv=rv+ch;
  }
  return rv;
}
int main(){
  while(getline(cin,s)){
    if(s[0]=='#')break;
    exist[s]=true;
  }
  getline(cin,s);
  maximum=-1;
  for(int i=0;i<27;i++){
    string rv=decode(s,i);
    istringstream iss(rv);
    int matches=0;
    while(iss>>word){
      if(exist.find(word)!=exist.end()){
	matches++;
      }
    }
    if(matches>maximum){
      maximum=matches;
      de=rv;
    }
  }
  int counter=0;
  istringstream iss(de);
  bool first=true;

  while(iss>>word){
    int next=counter+word.length();
    if(!first)next++;
    if(next>60){
      cout<<endl<<word;
      counter=word.length();
      first=false;
    }
    else{
      if(!first){
	cout<<" ";
      }
      cout<<word;
      counter=next;
      first=false;
    }
  }
    
  cout<<endl;
  return 0;
}

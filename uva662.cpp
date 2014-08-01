#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
typedef long long LL;
vector<string> split(string s,char delim){
  vector<string> rv;
  istringstream iss(s);
  string token;
  while(getline(iss,token,delim)){
    rv.push_back(token);
  }
  return rv;
}

int T;
string s;
LL eva(string s);
LL toInt(string s){
  LL rv;
  istringstream iss(s);
  iss>>rv;
  return rv;
}
bool posInt(string s){
  bool integer=true;
  for(int i=0;i<s.length();i++){
    if(!('0'<=s[i]&&s[i]<='9')){
      return false;
    }
  }
  return true;
}
LL eva_factor(string s){
  if(s=="")return -1;
  if(s[0]=='('&&s[s.length()-1]==')'){
    return eva(s.substr(1,s.length()-2));
  }
  if(!posInt(s)){
    return -1;
  }
  return toInt(s);
}
LL eva_comp(string s){
  if(s=="")return -1;
  LL para=0;
  int index=-1;
  for(int i=s.length()-1;i>=0;i--){
    if(s[i]=='*'){
      if(!para){
	index=i;
	break;
      }
    }
    else{
      if(s[i]==')'){
	para++;
      }
      if(s[i]=='('){
	para--;
      }
    }
  }
  LL fac=eva_factor(s.substr(index+1,s.length()-index-1));
  if(fac==-1)return -1;
  LL comp=(index!=-1)?eva_comp(s.substr(0,index)):1;
  if(comp==-1)return -1;
  return fac*comp;
}
LL eva(string s){
  LL para=0;
  int index=-1;
  if(s=="")return -1;
  for(int i=s.length()-1;i>=0;i--){
    if(s[i]=='+'){
      if(!para){
	index=i;
	break;
      }
    }
    else{
      if(s[i]==')'){
	para++;
      }
      if(s[i]=='('){
	para--;
      }
    }
  }
  LL comp=eva_comp(s.substr(index+1,s.length()-index-1));
  if(comp==-1)return -1;
  LL expression=(index!=-1)?eva(s.substr(0,index)):0;
  if(expression==-1)return -1;
  return comp+expression;
}
int main(){
  cin>>T;
  getline(cin,s);
  for(int t=0;t<T;t++){
    getline(cin,s);
    LL rv=eva(s);
    if(rv==-1){
      cout<<"ERROR"<<endl;
    }
    else{
      cout<<rv<<endl;
    }
  }
  return 0;
}

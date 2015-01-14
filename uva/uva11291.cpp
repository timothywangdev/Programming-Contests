#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

string s;
bool isInt(string s){
  bool integer=true;
  if(s.length()>=1&&s[0]=='-'){
    s=s.substr(1,s.length()-1);
  }
  for(int i=0;i<s.length();i++){
    if(!('0'<=s[i]&&s[i]<='9')){
      return false;
    }
  }
  return true;
}

double toDouble(string s){
  double rv;
  istringstream iss(s);
  iss>>rv;
  return rv;
}
double cal(string s){
  if(isInt(s)){
    return toDouble(s);
  }
  int index_1,index_2;
  for(int i=0;i<s.length();i++){
    if(s[i]==' '){
      index_1=i;
      break;
    }
  }
  double p=toDouble(s.substr(1,index_1));
  int para=0;
  for(int i=index_1+1;i<s.length();i++){
    if(s[i]=='(')para++;
    if(s[i]==')')para--;
    if(s[i]==' '&&!para){
      index_2=i;
      break;
    }
  }
  double part_1=cal(s.substr(index_1+1,index_2-index_1-1));
  double part_2=cal(s.substr(index_2+1,s.length()-index_2-2));
  return p*(part_1+part_2)+(1-p)*(part_1-part_2);
}
int main(){
  while(getline(cin,s)){
    if(s.length()>=2&&s[0]=='('&&s[1]==')')break;
    cout<<fixed<<setprecision(2)<<cal(s)<<endl;
  }
  return 0;
}

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

int T;

vector<string> split(string s,char delim){
  istringstream iss(s);
  string token;
  vector<string> rv;
  while(getline(iss,token,delim)){
    rv.push_back(token);
  }
  return rv;
}
int counter[26];
bool possible(string s){
  memset(counter,0,sizeof(counter));
  vector<string> v=split(s,'&');
  for(int i=0;i<v.size();i++){
    if(v[i].length()==1){
      if(counter[v[i][0]-'a']==0||counter[v[i][0]-'a']==1){
	counter[v[i][0]-'a']=1;
      }
      else{
	return false;
      }
    }
    else{
      if(counter[v[i][1]-'a']==0||counter[v[i][1]-'a']==2){
	counter[v[i][1]-'a']=2;
      }
      else{
	return false;
      }
    }
  }
  return true;
}
string s;
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>s;
    vector<string> v=split(s,'|');
    bool found=false;
    for(int i=0;i<v.size();i++){
      if(possible(v[i].substr(1,v[i].length()-2))){
	found=true;
	break;
      }
    }
    if(found){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}

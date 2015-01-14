#include <iostream>
#include <string>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int F,N,t;
bool enable[11];
map<char,int> toid;
string s;
bool possible(){
  for(int i=0;i<s.size();i++){
    if(!enable[toid[s[i]]]){
      return false;
    }
  }
  return true;
}
int main(){
  toid['q']=1;
  toid['a']=1;
  toid['z']=1;
  toid['w']=2;
  toid['s']=2;
  toid['x']=2;
  toid['e']=3;
  toid['d']=3;
  toid['c']=3;
  toid['r']=4;
  toid['f']=4;
  toid['v']=4;
  toid['t']=4;
  toid['g']=4;
  toid['b']=4;
  toid['y']=7;
  toid['h']=7;
  toid['n']=7;
  toid['u']=7;
  toid['j']=7;
  toid['m']=7;
  toid['i']=8;
  toid['k']=8;
  toid[',']=8;
  toid['o']=9;
  toid['l']=9;
  toid['.']=9;
  toid['p']=10;
  toid[';']=10;
  toid['/']=10;
  while(cin>>F>>N){
    memset(enable,true,sizeof(enable));
    vector<string> rv;
    int maximum=0;
    for(int i=0;i<F;i++){
      cin>>t;
      enable[t]=false;
    }
    for(int i=0;i<N;i++){
      cin>>s;
      if(possible()){
	if(s.length()>maximum){
	  rv.clear();
	  maximum=s.length();
	  rv.push_back(s);
	}
	else if(s.length()==maximum){
	  rv.push_back(s);
	}
      }
    }
    sort(rv.begin(),rv.end());
    vector<string> hehe;
    for(int i=0;i<rv.size();i++){	   
      bool found=false;
      for(int j=0;j<hehe.size();j++){
	if(hehe[j]==rv[i]){
	  found=true;
	  break;
	}
      }
      if(!found){
	hehe.push_back(rv[i]);
      }
    }
    cout<<hehe.size()<<endl;
    for(int i=0;i<hehe.size();i++){
      cout<<hehe[i]<<endl;
    }
  }
  return 0;
}

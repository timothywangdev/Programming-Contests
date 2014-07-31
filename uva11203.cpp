#include <iostream>
#include <string>

using namespace std;

int T;
string s;
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>s;
    int mc=0,ec=0,mindex,eindex;
    bool theorem=true;
    for(int i=0;i<s.size();i++){
      if(s[i]!='?'&&s[i]!='M'&&s[i]!='E'){
	theorem=false;
	break;
      }
      if(s[i]=='M'){
	if(mc==0){
	  mc=1;
	  mindex=i;
	}
	else{
	  theorem=false;
	  break;
	}
      }
      if(s[i]=='E'){
	if(ec==0){
	  ec=1;
	  eindex=i;
	}
	else{
	  theorem=false;
	  break;
	}
      } 
    }
    if(mindex>eindex){
      theorem=false;
    }
    if(mindex==0||eindex-mindex<2||s.length()-eindex<3){
      theorem=false;
    }
    if((s.length()-eindex)-(eindex-mindex)!=mindex){
      theorem=false;
    }
    if(theorem){
      cout<<"theorem"<<endl;
    }
    else{
      cout<<"no-theorem"<<endl;
    }
  } 
  return 0;
}


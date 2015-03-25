#include <bits/stdc++.h>

using namespace std;

bool boy[100],girl[100];
bool used[100][100][2][2];
int n,m;
int b,g,t;
bool check(){
  for(int i=0;i<n;i++){
    if(!boy[i])return false;
  }
  for(int i=0;i<m;i++){
    if(!girl[i])return false;
  }
}
int main(){
  memset(boy,false,sizeof(boy));
  memset(girl,false,sizeof(girl));
  memset(used,false,sizeof(used));
  cin>>n>>m;
  cin>>b;
  for(int i=0;i<b;i++){
    cin>>t;
    boy[t]=true;
  }
  cin>>g;
  for(int i=0;i<g;i++){
    cin>>t;
    girl[t]=true;
  }
  int day=0;
  int aa=0;
  int bb=0;
  bool changed=true;
  while(true){
    if(aa==0&&bb==0){
      if(!changed){
	if(check()){
	  cout<<"Yes"<<endl;
	}
	else{
	  cout<<"No"<<endl;
	}
	return 0;
      }
      changed=false;
    }
    
    if((boy[aa]&&!girl[bb])||(!boy[aa]&&girl[bb])){
      boy[aa]=girl[bb]=true;
      changed=true;
    }
    aa=(aa+1)%n;
    bb=(bb+1)%m;
  }
  return 0;
}

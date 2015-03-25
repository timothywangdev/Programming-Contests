#include <bits/stdc++.h>

using namespace std;

int n,m;
int main(){
  cin>>n>>m;
  bool r=true;
  for(int i=0;i<n;i++){
    if(i%2==1){
      if(r){
	for(int j=0;j<m-1;j++){
	  cout<<".";
	}
	cout<<"#";
	r=false;
      }
      else{
	cout<<"#";
	for(int j=0;j<m-1;j++){
	  cout<<".";
	}
	r=true;
      }
    }
    else{
      for(int j=0;j<m;j++){
	cout<<"#";
      }
    }
    cout<<endl;
  }
  return 0;
}

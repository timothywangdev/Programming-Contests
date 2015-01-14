#include <iostream>
#include <string>
#include <map>

using namespace std;

int n,m;

int main(){
  cin>>n>>m;
  map<string,string> mm;
  map<string,bool> f;
  string s1,s2;
  for(int i=0;i<m;i++){
    cin>>s1>>s2;
    mm[s1]=s2;
    mm[s2]=s1;
    f[s1]=true;
    f[s2]=false;
  }
  for(int i=0;i<n;i++){
    cin>>s1;
    s2=mm[s1];
    if(s1.length()<s2.length()){
      cout<<s1;
    }
    else if(s1.length()>s2.length()){
      cout<<s2;
    }
    else{
      if(f[s1]){
	cout<<s1;
      }
      else{
	cout<<s2;
      }
    }
    if(i!=n-1){
      cout<<" ";
    }
  }
  return 0;
}

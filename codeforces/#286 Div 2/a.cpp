#include <bits/stdc++.h>

using namespace std;

string s;
bool check(string &s){
  for(int i=0;i<s.length()/2;i++){
    if(s[i]!=s[s.length()-i-1]){
      return false;
    }
  }
  return true;
}
int main(){
  cin>>s;
  for(int i=0;i<26;i++){
    for(int j=0;j<=s.length();j++){
      string ss=s;
      ss.insert(j,1,'a'+i);
      if(check(ss)){
	cout<<ss<<endl;
	return 0;
      }
    }
  }
  cout<<"NA"<<endl;
  return 0;
}

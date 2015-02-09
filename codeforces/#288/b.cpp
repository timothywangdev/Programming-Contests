#include <bits/stdc++.h>

using namespace std;

string s;
int main(){
  cin>>s;
  char l=s[s.length()-1];
  for(int i=0;i<s.length()-1;i++){
    if(s[i]<=l&&(s[i]-'0')%2==0){
      swap(s[i],s[s.length()-1]);
      cout<<s<<endl;
      return 0;
    }
  }
  for(int i=s.length()-2;i>=0;i--){
    if(s[i]>l&&(s[i]-'0')%2==0){
      swap(s[i],s[s.length()-1]);
      cout<<s<<endl;
      return 0;
    }
  }
  cout<<"-1"<<endl;
  return 0;
}

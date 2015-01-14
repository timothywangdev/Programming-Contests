#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<int> rv;
string s1;

string gen(int k){
  string rv;
  for(int i=0;i<k;i++){
    rv=rv+')';
  }
  return rv;
}
bool check(){
  int left=0;
  for(int i=0;i<s1.length();i++){
    if(s1[i]=='(')left++;else left--;
    if(left<0){
      return false;
    }
  }
  if(left!=0)return false;
  return true;
}
int main(){
  cin>>s;
  s1=s;
  int t=0;
  int last=0;
  for(int i=0;i<s.length();i++){
    if(s[i]=='#'){
      s1[i]=')';
      t--;
      last=max(i,last);
    }
    if(s[i]=='('){
      t++;
    }
    if(s[i]==')'){
      t--;
    }
  }
  s1=s1.substr(0,last+1)+gen(t)+s1.substr(last+1,s.length()-last-1);
  if(!check()){
    cout<<"-1"<<endl;
    return 0;
  }
  for(int i=0;i<s.length();i++){
    if(s[i]=='#'){
      if(i==last){
	cout<<t+1<<endl;
      }
      else{
	cout<<"1"<<endl;
      }
    }
  }
  return 0;
}

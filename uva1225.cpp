#include <iostream>
#include <sstream>
#include <string.h>
#include <string>

using namespace std;
int T;
int c[10];
string toStr(int n){
  ostringstream oss;
  oss<<n;
  return oss.str();
}
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    int N;
    cin>>N;
    string s="";
    memset(c,0,sizeof(c));
    for(int i=1;i<=N;i++){
      s=s+toStr(i);
    }
    for(int i=0;i<s.size();i++){
      c[s[i]-'0']++;
    }
    for(int i=0;i<=9;i++){
      if(i!=0)cout<<" ";
      cout<<c[i];
    }
    cout<<endl;
  }
  return 0;
}

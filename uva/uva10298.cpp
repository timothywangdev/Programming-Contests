#include <iostream>
#include <string>
using namespace std;
string s;
int ne[30000001];

void kmp_init(string &P){
  int i=0, j=-1;ne[0]=-1;int m=P.length();
  while(i<m){
    while(j>=0&&P[i]!=P[j])j=ne[j];
    i++;j++;
    ne[i]=j;   
  }
}
int kmp(string &P, string &T, int start=0){
  kmp_init(P);
  int i=start,j=0;
  int n=T.length(),m=P.length();
  while(i<n){
    while(j>=0&&T[i]!=P[j])j=ne[j];
    i++;
    j++;
    if(j==m){
      return i-j;
    }
  }
}
int main(){
  while(getline(cin,s)){
      if(s=="."||s[0]=='.')break;
      string t=s+s;
      cout<<s.length()/kmp(s,t,1)<<endl;
  }
  return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int ne[101];

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
  while(i<2*n){
    while(j>=0&&i<n&&T[i]!=P[j]){
      j=ne[j];
    }
    i++;
    j++;
    if(j==m){
      return j-i+n;
    }
  }
}

int T,L,N;
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>L>>N;
    string rv;
    for(int i=0;i<N;i++){
      cin>>s;
      if(rv==""){
	rv=rv+s;
	continue;
      }
      int k=kmp(s,rv,rv.length()-L);
      rv=rv+s.substr(k,s.length()-k);
    }
    cout<<rv.length()<<endl;
  }
  return 0;
}

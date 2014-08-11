#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int L,pos,fi,fj;
int mo[7][2]={{0,1},{0,-1},{1,0},{-1,1},{-1,-1},{1,1},{1,-1}};
vector<string> v;
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
  while(i<2*n){
    while(j>=0&&T[i]!=P[j]){
      j=ne[j];
    }
    i++;
    j++;
    if(j==m){
      return i-j;
    }
  }
  return -1;
}

bool check(int r,int c,int k){
  for(int i=0;i<s.size();i++){
    if(0<=r&&r<L&&0<=c&&c<L){
      if(s[i]!=v[r][c]){
	return false;
      }
      r+=mo[k][0];
      c+=mo[k][1];
    }
    else{
      return false;
    }
  }
  fi=r-mo[k][0];
  fj=c-mo[k][1];
  return true;
}
int main(){
  cin>>L;
  v.clear();
  for(int i=0;i<L;i++){
   cin>>s;
   v.push_back(s);
  }
  while(cin>>s){
    if(s[0]=='0')break;
    bool found=false;
    for(int i=0;i<L&&!found;i++){
      for(int j=0;j<L&&!found;j++){
	for(int k=0;k<7&&!found;k++){
	  if(check(i,j,k)){
	    cout<<i+1<<","<<j+1<<" "<<fi+1<<","<<fj+1<<endl;
	    found=true;
	    break;
	  }
	}
      }
    }
    if(!found){
      cout<<"Not found"<<endl;
    }
  }

  return 0;
}

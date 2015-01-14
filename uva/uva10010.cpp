#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int T,N,M,C;
int L,pos,fi,fj;
int mo[8][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,1},{1,-1}};
vector<string> v;
string s;


bool check(int r,int c,int k){
  for(int i=0;i<s.size();i++){
    if(0<=r&&r<N&&0<=c&&c<M){
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
  cin>>T;
  for(int t=0;t<T;t++){
    if(t>0)cout<<endl;
    cin>>N>>M;
    v.clear();
    for(int i=0;i<N;i++){
      cin>>s;
      transform(s.begin(),s.end(),s.begin(),::toupper);
      v.push_back(s);
    }
    cin>>C;
    for(int i=0;i<C;i++){
      cin>>s;
      transform(s.begin(),s.end(),s.begin(),::toupper);
      bool found=false;
      for(int i=0;i<N&&!found;i++){
	for(int j=0;j<M&&!found;j++){
	  for(int k=0;k<8&&!found;k++){
	    if(check(i,j,k)){
	      cout<<i+1<<" "<<j+1<<endl;
	      found=true;
	      break;
	    }
	  }
	}
      }
   }
  }
  return 0;
}

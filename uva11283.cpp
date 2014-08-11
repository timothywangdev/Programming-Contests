#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int T,N;
int mo[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
string s;
string v[4];
bool used[4][4];
bool check(int r,int c,int pos){
  if(v[r][c]!=s[pos])return false;
  if(pos==s.length()-1)return true;
  used[r][c]=true;
  for(int i=0;i<8;i++){
    int rr=r+mo[i][0];
    int cc=c+mo[i][1];
    if(0<=rr&&rr<4&&0<=cc&&cc<4){
      if(!used[rr][cc]){
	if(check(rr,cc,pos+1)){
	  used[r][c]=false;
	  return true;
	}
      }
    }
  }
  used[r][c]=false;
  return false;
}
int getScore(int l){
  if(l==3||l==4)return 1;
  if(l==5)return 2;
  if(l==6)return 3;
  if(l==7)return 5;
  if(l>=8)return 11;
  return 0;
}
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>v[0]>>v[1]>>v[2]>>v[3];
    cin>>N;
    int sum=0;
    for(int i=0;i<N;i++){
      cin>>s;
      bool found=false;
      memset(used,false,sizeof(used));
      for(int r=0;r<4&&!found;r++){
	for(int c=0;c<4&&!found;c++){
	  if(check(r,c,0)){
	    sum+=getScore(s.length());
	    found=true;
	    break;
	  }
	}
      }
    }
    cout<<"Score for Boggle game #"<<t+1<<": "<<sum<<endl;
  }
  return 0;
}

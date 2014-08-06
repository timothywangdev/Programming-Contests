#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char m[100][100];
int final[100];
string s;
int T;
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>s;
    cout<<"Case #"<<t+1<<":"<<endl;
    for(int i=0;i<100;i++){
      for(int j=0;j<100;j++){
	m[i][j]=' ';
      }
    }
    int maxHeight=-2147483647,minHeight=2147483647;
    int height=0;
    bool needminus=true;
    for(int i=0;i<s.size();i++){
      if(s[i]=='R'){
	if(i==0||(i>0&&(s[i-1]=='F'||s[i-1]=='C')))height--;
	height++;
      }
      if(s[i]=='F'){
	if(i==0||(i>0&&s[i-1]=='R'))height++;
	height--;
      }
      if(s[i]=='C'){
	if(i>0&&s[i-1]=='R')height++;
      }
      if(height==maxHeight){
	if(s[i]=='C'){
	  needminus=false;
	}
      }
      else if(height>maxHeight){
	needminus=true;
      }
      // cout<<height<<endl;
      maxHeight=max(maxHeight,height);
      minHeight=min(minHeight,height);
    }
    height=0;
    if(minHeight<0){
      height+=0-minHeight;
      maxHeight+=0-minHeight;
    }
    //if(needminus)maxHeight--;
    for(int i=0;i<s.size();i++){
      if(s[i]=='R'){
	if(i==0||(i>0&&(s[i-1]=='F'||s[i-1]=='C')))height--;
	height++;
	m[i][height]='/';
      }
      if(s[i]=='F'){
	if(i==0||(i>0&&s[i-1]=='R'))height++;
	height--;
	m[i][height]='\\';
      }
      if(s[i]=='C'){
	if(i>0&&s[i-1]=='R')height++;
	m[i][height]='_';
      }
    }
    for(int i=maxHeight;i>=0;i--){
      for(int j=s.size()-1;j>=0;j--){
	if(m[j][i]!=' '){
	  final[i]=j;
	  break;
	}
      }
    }
    for(int i=maxHeight;i>=0;i--){
      cout<<"| ";
      for(int j=0;j<=final[i];j++){
	cout<<m[j][i];
      }
      cout<<endl;
    }
    cout<<"+";
    for(int i=0;i<=s.size()+1;i++){
      cout<<"-";
    }
    cout<<endl<<endl;
  }
  return 0;
}

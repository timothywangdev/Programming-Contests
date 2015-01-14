#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char m[10][10],tmp[10][10];
int mo[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
int minimum;
void flip(char m[][10],int i,int j){
  for(int k=0;k<5;k++){
    int r=i+mo[k][0];
    int c=j+mo[k][1];
    if(0<=r&&r<10&&0<=c&&c<10){
      if(m[r][c]=='O'){
	m[r][c]='#';
      }
      else{
	m[r][c]='O';
      }
    }
  }
}
int process(){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      tmp[i][j]=m[i][j];
    }
  }
  int count=0;
  for(int i=1;i<10;i++){
    for(int j=0;j<10;j++){
      if(tmp[i-1][j]=='O'){
	flip(tmp,i,j);
	count++;
      }
    }
  }
  for(int i=0;i<10;i++){
    if(tmp[9][i]=='O'){
      return 101;
    }
  }
  return count;
}
void permu(int i,int count){
  if(i==10){
    minimum=min(minimum,count+process());
    return;
  }
  permu(i+1,count);
  flip(m,0,i);
  permu(i+1,count+1);
  flip(m,0,i);
}
string s;
int main(){
  while(cin>>s){
    if(s=="end")break;
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
	cin>>m[i][j];
      }
    }
    minimum=101;
    permu(0,0);
    cout<<s<<" ";
    if(minimum>100){
      cout<<"-1"<<endl;
    }
    else{
      cout<<minimum<<endl;
    }
  }
  return 0;
}

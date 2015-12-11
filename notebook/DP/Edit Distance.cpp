#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string s[2];
int f[81][81];
int instruction[81][81];

int output(int i,int j){
  int counter=0;
  if(i==0){
    for(int k=1;k<=j;k++){
      counter++;
      cout<<counter<<" Insert "<<k<<","<<s[1][k-1]<<endl;
    }
    return counter;
  }
  if(j==0){
    for(int k=1;k<=i;k++){
      counter++;
      cout<<counter<<" Delete "<<"1"<<endl;
    }
    return counter;
  }
  if(instruction[i][j]==-1){
    counter=output(i-1,j-1);
    return counter;
  }
  else if(instruction[i][j]==2){
    counter=output(i-1,j-1);
    cout<<counter+1<<" Replace "<<j<<","<<s[1][j-1]<<endl;
    return counter+1;
  }
  else if(instruction[i][j]==1){
    counter=output(i-1,j);
    cout<<counter+1<<" Delete "<<j+1<<endl;
    return counter+1;
  }
  else{
    counter=output(i,j-1);
    cout<<counter+1<<" Insert "<<j<<","<<s[1][j-1]<<endl;
    return counter+1;
  }
}
bool first=true;
int main(){
  while(getline(cin,s[0])&&getline(cin,s[1])){
    if(!first)cout<<endl;
    if(first)first=false;
    memset(f,0,sizeof(f));
    memset(instruction,0,sizeof(instruction));
    for(int i=1;i<=s[0].length();i++){
      f[i][0]=i;
    }
    for(int j=1;j<=s[1].length();j++){
      f[0][j]=j;
    }
    for(int i=1;i<=s[0].length();i++){
      for(int j=1;j<=s[1].length();j++){
	f[i][j]=2147483647;
	if(s[0][i-1]==s[1][j-1]){
	  f[i][j]=f[i-1][j-1];
	  instruction[i][j]=-1;
	}
	else{
	  f[i][j]=f[i-1][j-1]+1;
	  instruction[i][j]=2;
	}
	// deletion
	if(f[i-1][j]+1<f[i][j]){
	  f[i][j]=f[i-1][j]+1;
	  instruction[i][j]=1;
	}

	// insertion
	if(f[i][j-1]+1<f[i][j]){
	  f[i][j]=f[i][j-1]+1;
	  instruction[i][j]=0;
	}
      }
    }
    cout<<f[s[0].length()][s[1].length()]<<endl;
    output(s[0].length(),s[1].length());
  }
  return 0;
}



#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int T,N,m[100][100];
int c[101];

bool hehe(){
  memset(c,0,sizeof(c));
  for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	c[m[i][j]]++;
      }
  }
  for(int i=0;i<=100;i++){
    if(c[i]>N)return false;
  }
 return true;
}
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>N;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	cin>>m[i][j];
      }
    }
    cout<<"Case "<<t+1<<": ";
    if(hehe()){
      cout<<"yes"<<endl;
    }
    else{
      cout<<"no"<<endl;
    }
  }
  return 0;
}

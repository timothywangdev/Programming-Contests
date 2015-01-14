#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
using namespace std;
typedef long long LL;
string s,a,b;
int T,K;

LL bi[51][51];

int toInt(string s){
  istringstream iss(s);
  int fuck;
  iss>>fuck;
  return fuck;
}
void split(string s){
  int i1,i2;
  i1=s.find('+');
  i2=s.find('^');
  a=s.substr(1,i1-1);
  b=s.substr(i1+1,i2-i1-2);
  K=toInt(s.substr(i2+1,s.length()-i2-1));
}
int main(){
  memset(bi,0,sizeof(bi));
  for(int i=0;i<=50;i++){
    for(int j=0;j<=i;j++){
      if(j==0){
	bi[i][j]=1;
      }
      else{
	bi[i][j]=bi[i-1][j-1]+bi[i-1][j];
      }
    }
  }
  cin>>T;
  for(int t=0;t<T;t++){
    cout<<"Case "<<t+1<<": ";
    cin>>s;
    split(s);
    for(int i=K;i>=0;i--){
      if(i!=K){
	cout<<"+";
      }
      if(bi[K][i]!=1){
	cout<<bi[K][i]<<"*";
      }
      if(i>0){
	cout<<a;
	if(i>1){
	  cout<<"^"<<i;
	}
      }
      if(K-i>0){
	if(i>0){
	  cout<<"*";
	}
	cout<<b;
	if(K-i>1){
	  cout<<"^"<<K-i;
	}
      }
    }
    cout<<endl;
  }
  return 0;
}

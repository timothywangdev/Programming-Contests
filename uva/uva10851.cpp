#include <iostream>
#include <string>
using namespace std;

int T;
string s;
string data[10];

int power(int base,int k){
  int rv=1;
  for(int i=0;i<k;i++){
    rv*=base;
  }
  return rv;
}
int main(){
  cin>>T;
  for(int t=0;t<T;t++){
    getline(cin,s);
    for(int i=0;i<=9;i++){
      getline(cin,data[i]);
    }
    for(int j=1;j<data[0].size()-1;j++){
      int sum=0;
      for(int i=1;i<=8;i++){
	sum+=(data[i][j]=='\\')?power(2,i-1):0;
      }
      cout<<(char)sum;
    }
    cout<<endl;
  }
  return 0;
}

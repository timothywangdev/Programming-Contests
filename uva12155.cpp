#include <iostream>
#include <cmath>
using namespace std;

int n,r1,c1,r2,c2,L;

char getChar(int r,int c){
  int l=(r<n)?(r+1)*2-1:L-2*(r-n+1);
  int dot=(L-l)/2;
  int delta=abs(r-n+1);
  int start=delta%26;
  if(c<dot)return '.';
  if(c<n){
    delta=(n-1-c);
    return (char)('a'+(start+delta)%26);
  }
  if(c<dot+l){
    delta=(c-(dot+l/2+1)+1);
    return (char)('a'+(start+delta)%26);
  }
  return '.';
}
int counter=0;
int main(){
  while(cin>>n>>r1>>c1>>r2>>c2){
    if(!n)break;
    counter++;
    cout<<"Case "<<counter<<":"<<endl;
    L=n*2-1;
    for(int i=r1;i<=r2;i++){
      for(int j=c1;j<=c2;j++){
	cout<<getChar(i%L,j%L);
      }
      cout<<endl;
    }
  }
  return 0;
}

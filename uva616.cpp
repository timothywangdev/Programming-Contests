#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long P;
bool check(long long N){
  long long p=P;
  for(long long i=1;i<=N;i++){
    p--;
    if(p%N!=0)
      return false;
    p-=p/N;
  }
  if(p%N!=0)
    return false;
  return true;
}
int main(){
  while(cin>>P){
    if(P<0)break;
    long long rv=-1;
    for(long long i=min((long long)10,P);i>=2;i--){
      if(check(i)){
	rv=i;
	break;
      }
    }
    cout<<P<<" coconuts, ";
    if(rv==-1){
      cout<<"no solution"<<endl;
    }
    else{
      cout<<rv<<" people and 1 monkey"<<endl;
    }
  }
  return 0;
}

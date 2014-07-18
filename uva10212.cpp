#include <iostream>

using namespace std;
typedef long long LL;

LL M,N,RV,MOD=1000000000;
int main(){
  while(cin>>M>>N){
  RV=1;
  if(N>M){
    cout<<"0"<<endl;
    continue;
  }
  if(M==0){
    cout<<"1"<<endl;
    continue;
  }
  for(LL i=M;i>=M-N+1;i--){
    RV*=i;
    while(RV%10==0){
      RV/=10;
    }
    RV%=MOD;
  }
  cout<<RV%10<<endl;
  }
  return 0;
}

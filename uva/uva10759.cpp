#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

typedef unsigned long long LL;

LL f[25][145];
LL N,X;
LL power(LL base, LL k){
  LL rv=1;
  for(LL i=0;i<k;i++){
    rv*=base;
  }
  return rv;
}
LL gcd(LL a, LL b){
  if(b==0)return a;
  return gcd(b,a%b);
}
int main(){
  memset(f,0,sizeof(f));
  f[0][0]=1;
  for(LL i=1;i<=24;i++){
    for(LL k=i;k<=6*i;k++){
      for(LL j=1;j<=6;j++){
	if(k>=j){
	  f[i][k]+=f[i-1][k-j];
	}
      }
    }
  }
  while(cin>>N>>X){
    if(!N&&!X)break;
    LL sum=0;
    for(LL x=X;x<=N*6;x++){
      sum+=f[N][x];
    }
    LL tmp=power(6,N);
    LL g=gcd(sum,tmp);
    sum/=g;
    tmp/=g;
    if(sum%tmp==0){
      cout<<sum/tmp<<endl;
    }
    else{
      cout<<sum<<"/"<<tmp<<endl;
    }
  }
  return 0;
}

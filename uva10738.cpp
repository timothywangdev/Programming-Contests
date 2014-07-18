#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
typedef long long LL;

bool squareFree[1000001];
LL numDiff[1000001];

void sieve(LL MAX_N){
  memset(squareFree,true,sizeof(squareFree));
  memset(numDiff,0,sizeof(numDiff));
  for(LL i=2;i<=MAX_N;i++){
    
    if(!squareFree[i]){
      for(LL j=i;j<=MAX_N;j+=i){
	squareFree[j]=false;
      }
    }
    
    if(numDiff[i]==0){
      for(LL j=i;j<=MAX_N;j+=i){
	numDiff[j]++;
	if(j==i*i){
	  squareFree[j]=false;
	}
      }
    }
  }
}

LL M[1000001],mu[1000001],N;
int main(){
  sieve(1000000);
  mu[1]=M[1]=1;
  for(LL i=2;i<=1000000;i++){
    if(!squareFree[i]){
      mu[i]=0;
    }
    else{
      if(numDiff[i]%2==0){
	mu[i]=1;
      }
      else{
	mu[i]=-1;
      }
    }
  }
 for(LL i=2;i<=1000000;i++){
   M[i]=M[i-1]+mu[i];
 }
  while(cin>>N){
    if(!N)break;
    cout<<fixed<<setw(8)<<N<<setw(8)<<mu[N]<<setw(8)<<M[N]<<endl;
  }
  return 0;
}

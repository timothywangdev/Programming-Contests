#include <iostream>
#include <string.h>
using namespace std;

typedef long long LL;

LL phi[2000001],depth[2000001],sum[2000001];

void sieve(LL MAX_N){
  for(LL i=1;i<=MAX_N;i++){
    phi[i]=i;
  }
  for(LL i=2;i<=MAX_N;i++){
    if(phi[i]==i){ // prime
       for(LL j=i;j<=MAX_N;j+=i){
	 phi[j]=(phi[j]*(i-1))/i;
       } 
    }
  }
}


LL T,M,N;
int main(){
  memset(depth,0,sizeof(depth));
  sum[0]=0;
  sum[1]=0;
  depth[1]=0;
  sieve(2000000);

  for(LL i=2;i<=2000000;i++){
    LL k=phi[i];
    if(k==1||depth[k]!=0){
      depth[i]=depth[k]+1;
    }
    sum[i]=sum[i-1]+depth[i];
  }
  
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>M>>N;
    cout<<sum[N]-sum[M-1]<<endl;
  }
  return 0;
}

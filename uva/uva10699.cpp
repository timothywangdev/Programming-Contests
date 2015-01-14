#include <iostream>
#include <string.h>
using namespace std;
typedef long long LL;

LL numDiffPF[1000001];
void sieve(LL MAX_N){
  memset(numDiffPF,0,sizeof(numDiffPF));
  for(LL i=2;i<=MAX_N;i++){
    if(numDiffPF[i]==0){
      for(LL j=i;j<=MAX_N;j+=i){
	numDiffPF[j]++;
      }
    }
  }
}
LL N;
int main(){
  sieve(1000000);
  while(cin>>N){
    if(!N)break;
    cout<<N<<" : "<<numDiffPF[N]<<endl;
  }
  return 0;
}

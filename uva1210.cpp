#include <iostream>
#include <bitset>
#include <vector>
#include <utility>
#include <cmath>
#include <map>
#include <string.h>
using namespace std;
typedef long long LL;
typedef vector<LL> vi;
LL _sieve_size;
bitset<2147483648> bs;
vi primes;


int N;
LL f[2000][2000];
LL counter[10001];
void sieve(LL upperbound){
  _sieve_size=upperbound+1;
  bs.set();
  bs[0]=bs[1]=0;
  for(LL i=2;i<=_sieve_size;i++){
    if(bs[i]){
      for(LL j=i*i;j<=_sieve_size;j+=i){
         bs[j]=0;
      }
      primes.push_back(i);
    }
  }
}
int main(){
  sieve(10000);
  memset(f,0,sizeof(f));
  memset(counter,0,sizeof(counter));
  for(int i=0;i<primes.size()-1;i++){
    for(int j=i;j<primes.size();j++){
      if(j>0){
	f[i][j]+=f[i][j-1];
      }
      f[i][j]+=primes[j];
      if(f[i][j]<=10000){
	counter[f[i][j]]++;
      }
    }
  }
  
  while(cin>>N){
    if(!N)break;
    cout<<counter[N]<<endl;
  }
  return 0;
}

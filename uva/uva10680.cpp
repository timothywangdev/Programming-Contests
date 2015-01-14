#include <iostream>
#include <bitset>
#include <vector>
#include <utility>
#include <cmath>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef vector<LL> vi;
LL _sieve_size,SN=78498,need;
bitset<2147483648> bs;
vi primes;

LL counter[78498];
int rem[1000001];
int getPos[1000001];

long long mpow(long long x, long long y, long long mod) {
	long long ret = 1;
	while(y) {
    	if(y&1)
        	ret *= x, ret %= mod;
    	y >>= 1;
    	x = x*x, x %= mod;
	}
	return ret;
}

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
       getPos[i]=primes.size()-1;
    }
  }
}

void primeFactors(LL n){
  //vi factors;
  LL PF_idx=0;
  LL PF=primes[PF_idx];
  while(PF*PF<=n){
    LL c=0;
    while(n%PF==0){
      n/=PF;
      c++;
    }
    if(counter[PF_idx]<c){
      need=(need*mpow(PF,c-counter[PF_idx],10000000))%10000000;
      counter[PF_idx]=c;
    }
    PF_idx++;
    PF=primes[PF_idx];
  }
  if(n!=1){
    LL pos=getPos[n];
     if(counter[pos]<1){
       need=(need*mpow(n,1-counter[pos],10000000))%10000000;
      counter[pos]=1;
    }
  }
}

bool isPrime(LL n){
  if(n<=_sieve_size)return bs[n];
  if(bs[n]==1)return true;
  for(int i=0;i<primes.size();i++){
    if(n%primes[i]==0)return false;
  }
  bs[n]=1;
  return true;
}

LL N;



int main(){
  sieve(1000001);
  memset(counter,0,sizeof(counter));
  LL rv=1;
  rem[1]=1;
  rem[2]=2;
  for(LL i=2;i<=1000000;i++){
    need=1;
    primeFactors(i);
    while(need%10==0){
      need/=10;
    }
    rv=(rv*need)%10000000;
    while(rv%10==0){
      rv/=10;
    }
    rem[i]=rv;
  }

  while(cin>>N){
    if(!N)break;
    cout<<rem[N]%10<<endl;
  }
  return 0;
}


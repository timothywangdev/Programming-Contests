#include <iostream>
#include <bitset>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;
typedef long long LL;
typedef vector<LL> vi;
LL _sieve_size;
bitset<2147483648> bs;
vi primes;

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

LL primeFactors(LL n){
  vi factors;
  LL PF_idx=0;
  LL PF=primes[PF_idx];
  LL rv=1;
  while(PF*PF<=n){
    LL c=0;
    while(n%PF==0){
      n/=PF;
      //factors.push_back(PF);
      c++;
    }
    rv=rv*(c+1);
    PF_idx++;
    PF=primes[PF_idx];
  }
  if(n!=1)//factors.push_back(n);
    {
      rv*=2;
    }
  return rv;
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

LL T,L,U;

int main(){
  sieve(31700);
  cin>>T;
  for(LL t=0;t<T;t++){
    cin>>L>>U;
    LL maximum=-1,target;
    for(LL i=L;i<=U;i++){
      LL k=primeFactors(i);
      if(k>maximum){
	maximum=k;
	target=i;
      }y
    }
    cout<<"Between "<<L<<" and "<<U<<", "<<target<<" has a maximum of "<<maximum<<" divisors."<<endl;
  }
  return 0;
}

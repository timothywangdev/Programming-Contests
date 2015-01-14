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

vi primeFactors(LL n){
  vi factors;
  LL PF_idx=0;
  LL PF=primes[PF_idx];
  while(PF*PF<=n){
    LL counter=0;
    while(n%PF==0){
      n/=PF;
      counter++;
      // factors.push_back(PF);
    }
    if(counter>=1){
      factors.push_back(PF);
    }
    PF_idx++;
    PF=primes[PF_idx];
  }
  if(n!=1)factors.push_back(n);
  return factors;
}

LL T,N,sum;

bool isPrime(LL n){
  if(n<=_sieve_size)return bs[n];
  if(bs[n]==1)return true;
  for(int i=0;i<primes.size();i++){
    if(n%primes[i]==0)return false;
  }
  bs[n]=1;
  return true;
}

int main(){
  sieve(10000000);
  while(cin>>N){
    if(!N)break;
    N=abs(N);
    vi rv=primeFactors(N);
    if(rv.size()>=2){
      cout<<rv[rv.size()-1]<<endl;
    }
    else{
      cout<<"-1"<<endl;
    }
  }
  return 0;
}

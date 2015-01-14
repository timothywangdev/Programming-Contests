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
  LL rv=0;
  while(PF*PF<=n){
    LL c=0;
    while(n%PF==0){
      n/=PF;
      //factors.push_back(PF);
      c++;
    }
    rv++;
    PF_idx++;
    PF=primes[PF_idx];
  }
  if(n!=1)//factors.push_back(n);
    {
      rv++;
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

LL EulerPhi(LL N){
  LL PF_idx=0, PF = primes[PF_idx], ans= N;
  while(PF*PF<=N){
    if(N%PF==0)ans-=ans/PF;
    while(N%PF==0){
      N/=PF;
    }
    PF_idx++;
    PF=primes[PF_idx];
  }
  if(N!=1)ans-=ans/N;
  return ans;
}
int main(){
  sieve(32000);
  while(cin>>T){
    if(!T)break;
    cout<<EulerPhi(T)<<endl;
  }
  return 0;
}

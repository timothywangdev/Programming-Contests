#include <iostream>
#include <bitset>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
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

LL N;

LL sumDiv(LL N){
  LL PF_idx=0;
  LL PF=primes[PF_idx],ans=1;
  while(PF*PF<=N){
    LL power=0;
    while(N%PF==0){
      N/=PF;
      power++;
    }
    ans*=((LL)pow((double)PF,power+1.0)-1)/(PF-1);
    PF_idx++;
    PF=primes[PF_idx];
  }
  if(N!=1){
    ans*=((LL)pow((double)N,2.0)-1)/(N-1);
  }
  return ans;
}
LL counter=0;
int main(){
  sieve(10000);
  while(cin>>N){
    if(!N)break;
    counter++;
    cout<<"Case "<<counter<<": ";
    LL rv=-1;
    for(int i=1;i<=2*N;i++){
      if(sumDiv(i)==N){
	rv=max(rv,(LL)i);
      }
    }
     cout<<rv<<endl;
  }

  return 0;
}

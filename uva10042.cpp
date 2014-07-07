#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
typedef long long LL;
typedef vector<LL> vi;
LL _sieve_size;
bitset<100010> bs;
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
    while(n%PF==0){
      n/=PF;
      factors.push_back(PF);
    }
    PF_idx++;
    PF=primes[PF_idx];
  }
  if(n!=1)factors.push_back(n);
  return factors;
}

LL T,N,sum;

LL getSum(int n){
  LL sum=0;
  while(n>0){
    sum+=n%10;
    n/=10;
  }
  return sum;
}
bool isPrime(LL n){
  if(n<=_sieve_size)return bs[n];
  for(int i=0;i<primes.size();i++){
    if(n%primes[i]==0)return false;
  }
  return true;
}
int main(){
  sieve(100000);

  cin>>T;
  for(int t=0;t<T;t++){
    cin>>N;
    for(LL i=N+1;;i++){
      if(!isPrime(i)){
	vi factors=primeFactors(i);
	sum=0;
	for(LL j=0;j<factors.size();j++){
	  sum+=getSum(factors[j]);
	}
	if(sum==getSum(i)){
	  cout<<i<<endl;
	  break;
	}
      }
    }
  }
  return 0;
}

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
  if(bs[n]==1)return true;
  for(int i=0;i<primes.size();i++){
    if(n%primes[i]==0)return false;
  }
  bs[n]=1;
  return true;
}

void seg_sieve(LL L,LL U){
  for(LL i=0;i<primes.size();i++){
    if(primes[i]*primes[i]>U)break;
    for(LL j=(L/primes[i])*primes[i];j<=U;j+=primes[i]){
      if(j<=primes[i])continue;
      if(j!=2){
	bs[j]=0;
      }
    }
  }
}

LL a,b,maxA,maxB,maxD,minA,minB,minD;
int main(){
  sieve(sqrt((double)2147483647));
  while(cin>>a>>b){
    seg_sieve(a,b);
    LL last=-1;
    maxD=0;
    minD=2147483647;
    /*
    if(a%2==0){
      if(bs[a]){
	last=a;
      }
      a++;
    }
    */
    for(LL i=a;i<=b;i++){
      if(bs[i]){
	if(last==-1){
	  last=i;
	}
	else{
	  LL d=i-last;
	  if(d>maxD){
	    maxD=d;
	    maxA=last;
	    maxB=i;
	  }
	  if(d<minD){
	    minD=d;
	    minA=last;
	    minB=i;
	  }
	  last=i;
	}
      }
    }
    if(maxD){
      cout<<minA<<","<<minB<<" are closest, "<<maxA<<","<<maxB<<" are most distant."<<endl;
    }
    else{
      cout<<"There are no adjacent primes."<<endl;
    }
  }
  return 0;
}

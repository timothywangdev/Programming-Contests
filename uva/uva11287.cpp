#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;

typedef unsigned long long LL;
typedef vector<LL> vl;
bitset<2147483648> bs;
vl primes;
LL _sieve_size;
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

bool isPrime(LL n){
  if(n<=_sieve_size)return bs[n];
  for(int i=0;i<primes.size();i++){
    if(n%primes[i]==0)return false;
  }
  return true;
}

LL mpow(LL x, LL y, LL mod) {
	LL ret = 1;
	while(y) {
    	if(y&1)
        	ret *= x, ret %= mod;
    	y >>= 1;
    	x = x*x, x %= mod;
	}
	return ret;
}

LL P,A;

int main(){
  sieve(1000000);
  while(cin>>P>>A){
    if(!P&&!A)break;
    //cout<<"mod: "<<mpow(A,P,P)<<endl;
    if(!isPrime(P)&&A==mpow(A,P,P)){
      cout<<"yes"<<endl;
    }
    else{
      cout<<"no"<<endl;
    }
  }
  return 0;
}

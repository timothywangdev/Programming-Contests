#include <iostream>
#include <bitset>
#include <vector>
#include <utility>
using namespace std;
typedef long long LL;
typedef vector<LL> vi;
LL _sieve_size;
bitset<100000010> bs;
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

vector<pair<int,int> > pairs;
int n;
int main(){
  sieve(20000000);
  for(int i=0;i<primes.size()-1;i++){
    if(primes[i]+2==primes[i+1]){
      pairs.push_back(make_pair(primes[i],primes[i+1]));
    }
  }
  while(cin>>n){
    cout<<"("<<pairs[n-1].first<<", "<<pairs[n-1].second<<")"<<endl;
  }
  return 0;
}

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
map<LL,LL> getPos;
class factors{
public:
  LL counter[4806];
  factors(){
    memset(counter,0,sizeof(counter));
  }
};
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

vector<pair<LL,LL> > primeFactors(LL n){
  vector<pair<LL,LL> > factors;
  LL PF_idx=0;
  LL PF=primes[PF_idx];
  while(PF*PF<=n){
    int counter=0;
    while(n%PF==0){
      n/=PF;
      counter++;
    }
    if(counter>=1){
      factors.push_back(make_pair(PF,counter));
    }
    PF_idx++;
    PF=primes[PF_idx];
  }
  if(n!=1){
    factors.push_back(make_pair(n,1));
  }
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

LL get_powers(LL n, LL p){
  LL res=0;
  for(LL power=p;power<=n;power*=p){
    res+=n/power;
  }
  return res;
}

int main(){
  sieve(46500);
  //cout<<primes.size()<<endl;
  while(cin>>T>>N){
    vector<pair<LL,LL> > f=primeFactors(N);
    bool found=true;
    for(LL i=0;i<f.size();i++){
      LL p=get_powers(T,f[i].first);
      if(p<f[i].second){
	found=false;
	break;
      }
    }
    if(found){
      cout<<N<<" divides "<<T<<"!"<<endl;
    }
    else{
      cout<<N<<" does not divide "<<T<<"!"<<endl;
    }
  }

  return 0;
}

#include <iostream>
#include <bitset>
#include <vector>
#include <utility>
#include <cmath>
#include <string.h>
using namespace std;
typedef long long LL;
typedef vector<LL> vi;
LL _sieve_size;
bitset<2147483648> bs;
vi primes;
LL counter[2][664579];
LL getPos[10000001];
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

vector<pair<LL,LL> > primeFactors(LL n,int index){
  vector<pair<LL,LL> > factors;
  LL PF_idx=0;
  LL PF=primes[PF_idx];
  while(PF*PF<=n){
    LL c=0;
    while(n%PF==0){
      n/=PF;
      c++;
    }
    if(c>0){
      factors.push_back(make_pair(PF,c));
    }
    // counter[index][PF_idx]+=c;
    PF_idx++;
    PF=primes[PF_idx];
  }
  if(n!=1){
    factors.push_back(make_pair(n,1));
    //counter[index][getPos[n]]+=1;
  }
  return factors;
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
LL T,A,C;
int main(){
  sieve(10000001);
  cin>>T;
  for(int t=0;t<T;t++){
    cin>>A>>C;
    //memset(counter,0,sizeof(counter));
    vector<pair<LL,LL> > r1,r2;
    r1=primeFactors(A,0);
    r2=primeFactors(C,1);
    for(LL i=0;i<r1.size();i++){
       LL k=r1[i].first;
       LL pos=getPos[k];
       counter[0][pos]=counter[1][pos]=0;
    }
    for(LL i=0;i<r2.size();i++){
       LL k=r2[i].first;
       LL pos=getPos[k];
       counter[0][pos]=counter[1][pos]=0;
    }
    for(LL i=0;i<r1.size();i++){
       LL k=r1[i].first;
       LL pos=getPos[k];
       counter[0][pos]=r1[i].second;
    }
    for(LL i=0;i<r2.size();i++){
       LL k=r2[i].first;
       LL pos=getPos[k];
       counter[1][pos]=r2[i].second;
    }
    LL rv=1;
    bool impossible=false;
    for(LL i=0;i<r1.size();i++){
      LL k=r1[i].first;
      LL pos=getPos[k];
      if(counter[0][pos]>counter[1][pos]){
	impossible=true;
	break;
      }
    }
    if(!impossible){
      for(LL i=0;i<r2.size();i++){
	LL k=r2[i].first;
	LL pos=getPos[k];
	if(counter[1][pos]>counter[0][pos]){
	  rv=rv*pow(k,counter[1][pos]);
	}
      }
    }
    if(!impossible){
      cout<<rv<<endl;
    }
    else{
      cout<<"NO SOLUTION"<<endl;
    }
  }
  return 0;
}

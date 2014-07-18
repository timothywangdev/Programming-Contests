#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <bitset>
using namespace std;
typedef long long LL;
typedef vector<LL> vi;
LL _sieve_size;
bitset<10000000> bs;
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

vector<pair<int,int> > primeFactors(LL n){
  vector<pair<int,int> > factors;
  LL PF_idx=0;
  LL PF=primes[PF_idx];
  while(PF*PF<=n){
    int k=0;
    while(n%PF==0){
      n/=PF;
      k++;
    }
    if(k!=0){
      factors.push_back(make_pair(PF,k));
    }
    PF_idx++;
    PF=primes[PF_idx];
  }
  if(n!=1)factors.push_back(make_pair(n,1));
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


bool process(string s){
  istringstream iss(s);
  int a,b;
  int n=1;
  while(iss>>a>>b){
    n*=pow(a,b);
  }
  vector<pair<int,int> > rv=primeFactors(n-1);
  for(int i=rv.size()-1;i>=0;i--){
    if(i<rv.size()-1)cout<<" ";
    cout<<rv[i].first<<" "<<rv[i].second;
  }
  cout<<endl;
}
string s;
int main(){
  sieve(32768);
  while(getline(cin,s)){
    if(s=="0")break;
    process(s);
  }
  return 0;
}

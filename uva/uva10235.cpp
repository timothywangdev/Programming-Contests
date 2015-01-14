#include <iostream>
#include <bitset>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>
#include <string>
#include <cmath>
#include <map>
#include <string.h>
using namespace std;
typedef long long LL;
typedef vector<LL> vi;
LL _sieve_size;
bitset<2147483648> bs;
vi primes;


LL N;
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

LL toLL(string s){
  LL rv;
  istringstream iss(s);
  iss>>rv;
  return rv;
}
bool rev(LL n){
  ostringstream oss;
  oss<<n;
  string s=oss.str();
  reverse(s.begin(),s.end());
  LL p=toLL(s);
  if(p!=n){
    return bs[p];
  }
  else{
    return false;
  }
}
int main(){
  sieve(10000000);
  while(cin>>N){
    cout<<N;
    if(bs[N]){
      if(rev(N)){
	cout<<" is emirp."<<endl;
      }
      else{
	cout<<" is prime."<<endl;
      }
    }
    else{
      cout<<" is not prime."<<endl;
    }
  }
  return 0;
}

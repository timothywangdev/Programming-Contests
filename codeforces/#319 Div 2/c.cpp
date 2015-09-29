#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,a,b) for(int i=(b);i>=(a);i--)
#define F(i,n) for(int i=0;i<(n);i++)
#define FR(i,n) for(int i=(n)-1;i>=0;i--)
#define R(a,i,b) (a<=i&&i<=b)
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;
typedef long long LL;


bitset<1001> bs;
vector<int> primes;
int n;

void sieve(LL upperbound){
  int _sieve_size=upperbound+1;
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

vector<int> co;
int main(){
  sieve(1000);
  co=vector<int>(primes.size(),0);
  cin>>n;
  for(int i=2;i<=n;i++){
    int k=i;
    F(j,primes.size()){
      int c=0;
      while(k%primes[j]==0){
	k/=primes[j];
	c++;
      }
      co[j]=max(co[j],c);
    }
  }
  int sum=0;
  F(i,primes.size()){
    sum+=co[i];
  }
  cout<<sum<<endl;
  F(i,primes.size()){
    if(co[i]==0)continue;
    int k=primes[i];
    F(j,co[i]){
      cout<<k<<" ";
      k*=primes[i];
    }
  }
  
   return 0;
}

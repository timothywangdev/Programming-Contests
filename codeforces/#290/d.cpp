#include <bits/stdc++.h>
#define INF 960000001
#define BITMASK_LIMIT 512
using namespace std;
typedef long long LL;
int n;
LL l[301];
int p[301];
LL c[301];
LL f[301][BITMASK_LIMIT];
vector<LL> primes;
vector<pair<LL,LL> > factors;
LL minimum=INF;
int target;
bitset<100000> bs;
LL search(int i,int mask){
  if(i>n){
    if(mask==0){
      return 0;
    }
    return INF;
  }
  if(f[i][mask]!=-1)return f[i][mask];
  LL &ret=f[i][mask];
  if(i!=target){
    ret=min(search(i+1,mask),search(i+1,mask&p[i])+c[i]);
  }
  else{
    ret=search(i+1,mask&p[i])+c[i];
  }
  ret=min(ret,(LL)INF);
  return ret;
}
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
vector<pair<LL,LL> > prime_factors(LL n){
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

int main(){
  sieve(31623);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>l[i];
  }
  for(int i=1;i<=n;i++){
    cin>>c[i];
  }
  for(int i=1;i<=n;i++){
    memset(f,-1,sizeof(f));
    factors=prime_factors(l[i]);
    for(int j=1;j<=n;j++){
      p[j]=0;
      for(int k=0;k<factors.size();k++){
	if(l[j]%factors[k].first==0)
	  p[j]|=(1<<k);
      }
    }
    target=i;
    minimum=min(minimum,search(1,(1<<factors.size())-1));
  }
  if(minimum==INF){
    cout<<"-1"<<endl;
  }
  else{
    cout<<minimum<<endl;
  }
  return 0;
}

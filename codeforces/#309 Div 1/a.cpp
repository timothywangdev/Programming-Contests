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

#define MAXN 2000

LL MOD=1000000007;
LL factorial[MAXN];

LL pow_mod_base2(LL base, LL exp, LL mod){
  LL rv=1;
  base=base%mod;
  while(exp>0){
    if(exp&1){
      rv=(rv*base)%mod;
    }
    exp>>=1;
    base=(base*base)%mod;
  }
  return rv;
}
LL inv(LL n,LL mod){
  //assert(n!=0);
  return pow_mod_base2(n,mod-2,mod);
}

LL C(LL n, LL k, LL mod){
    if(n<k)return 0;
    return factorial[n]*inv(factorial[n-k],mod)%mod*inv(factorial[k],mod)%mod;
}
LL sum[1001];
LL c[1001],f[1001];

int main(){

  factorial[0]=1;
  for(int i=1;i<=2000;i++){
    factorial[i]=(factorial[i-1]*i)%MOD;
  }

  int n;
  cin>>n;
  sum[0]=0;
  for(int i=1;i<=n;i++){
    cin>>c[i];
    sum[i]=sum[i-1]+c[i];
    if(i==1){
      f[i]=1;
      continue;
    }
    f[i]=(f[i-1]*C(sum[i-1]+c[i]-1,sum[i-1],MOD))%MOD;
  }
  cout<<f[n]%MOD<<endl;
  return 0;
}

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

#define MAXN 100000
#define MOD 1000000007
LL c_k[MAXN],c_k1[MAXN],inv[MAXN+1],sum1[MAXN],powten[MAXN];
int n,k;
string s;
int main(){
   memset(c_k,0,sizeof(c_k));
   memset(c_k1,0,sizeof(c_k1));
   cin>>n>>k>>s;
   powten[0]=1;
   for(int i=1;i<n;i++){
      powten[i]=(powten[i-1]*10)%MOD;
   }
   inv[1]=1%MOD;
   for(int i=2;i<=n;i++){
      inv[i]=MOD-(inv[MOD%i]*(MOD/i))%MOD;
      //cout<<inv[i]<<" "<<Inv(i)<<endl;
   }
   c_k[k]=c_k1[k-1]=1;
   for(int i=k+1;i<n;i++){
      c_k[i]=(((c_k[i-1]*i)%MOD)*inv[i-k])%MOD;
      // cout<<c_k[i]<<" "<<C(i,k)<<endl;
   }
   for(int i=k;i<n;i++){
      c_k1[i]=(((c_k1[i-1]*i)%MOD)*inv[i-k+1])%MOD;
      //cout<<c_k1[i]<<" "<<C(i,k-1)<<endl;
   }
   LL sum=0;
   for(int i=0;i<n;i++){
      sum=(sum+(c_k[i]*(powten[n-i-1]*(LL)(s[i]-'0'))%MOD)%MOD)%MOD;
   }
   sum1[0]=0;
   for(int i=1;i<n;i++){
      sum1[i]=(sum1[i-1]+(c_k1[n-i-1]*powten[i-1])%MOD)%MOD;
   }
   for(int i=0;i<n;i++){
      sum=(sum+(sum1[n-i-1]*(LL)(s[i]-'0'))%MOD)%MOD;
   }
   cout<<sum<<endl;
   return 0;
}

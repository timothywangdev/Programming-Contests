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
typedef unsigned long long LL;

LL n,k,x,a[200000],le[200000],ri[200000];
int main(){
  cin>>n>>k>>x;
  F(i,n){
    cin>>a[i];
  }
  LL t=1;
  F(i,k){
    t=t*x;
  }
  F(i,n){
    if(i==0){
      le[i]=a[i];
    }
    else{
      le[i]=le[i-1]|a[i];
    }
  }
  FR(i,n){
    if(i==n-1){
      ri[i]=a[i];
    }
    else{
      ri[i]=ri[i+1]|a[i];
    }
  }
  LL rv=0;
  F(i,n){
    if(i==0){
      rv=max(rv,(a[i]*t)|(n>1?ri[i+1]:0));
    }
    else if(i==n-1){
      rv=max(rv,(a[i]*t)|(n>1?le[i-1]:0));
    }
    else{
      rv=max(rv,(a[i]*t)|le[i-1]|ri[i+1]);
    }
  }
  cout<<rv<<endl;
   return 0;
}

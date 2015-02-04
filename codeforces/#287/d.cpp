#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL n,k,m,rem,t;
LL f[1001][100][2],power10_m[1001],power10_k[1001];
LL solve(LL i,LL j,bool non_zero){
  if(j==0&&non_zero){
    return (i==n)?1:(power10_m[n-i-1]*9LL)%m;
  }
  if(i==n){
    return 0;
  }
  LL &rv=f[i][j][non_zero];
  if(rv!=-1){
    return rv;
  }
  rv=0;
  for(LL d=0;d<=9;d++){
    rv=(rv+solve(i+1,(j+d*power10_k[i])%k,non_zero||(d!=0)))%m;
  }
  return rv;
}
int main(){
  cin>>n>>k>>m;
  power10_m[0]=power10_k[0]=1;
  memset(f,-1,sizeof(f));
  for(int i=1;i<=n;i++){
    power10_k[i]=(power10_k[i-1]*10)%k;
    power10_m[i]=(power10_m[i-1]*10)%m;
  }
  cout<<solve(0,0,0)<<endl;
  return 0;
}

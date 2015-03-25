#include <bits/stdc++.h>
#define MAXN 100000
#define MOD 1e+9
using namespace std;
typedef vector<int> VI;
typedef long long LL;
LL sum[MAXN+1],sum2[MAXN+1],f[MAXN+1];
int next[MAXN+1];
char s[MAXN+1],t[MAXN+1];
bool good[MAXN+1];
LL n,m;
LL mod=(LL)MOD+7;


void KMP_preprocess(char P[],int m,int next[]){
  int i=0,j=-1;
  next[0]=-1;
  while(i<m){
    while(j>=0&&P[i]!=P[j])j=next[j];
    i++;j++;
    next[i]=j;
  }
}
void KMP(char T[],char P[],int next[],int n,int m,int start=0){
  int i=start,j=0;
  KMP_preprocess(P,m,next);
  while(i<n){
    while(j>=0&&T[i]!=P[j])j=next[j];
    i++;j++;
    if(j==m){
      // returning index=i-j
      good[i]=true;
      j=next[j];
    }
  }
}
int main(){
  scanf("%s%s",s,t);
  n=strlen(s),m=strlen(t);
  memset(good,false,sizeof(good));
  KMP(s,t,next,n,m);
  sum[0]=1;
  sum2[0]=1;
  f[0]=0;
  for(int i=1;i<=n;i++){
    if(!good[i]){
      f[i]=f[i-1];
    }
    else{
      f[i]=sum2[i-m];
    }
    sum[i]=(sum[i-1]+f[i])%mod;
    sum2[i]=(sum2[i-1]+sum[i])%mod;
  }
  cout<<(sum[n]+mod-1)%mod<<endl;
  return 0;
}

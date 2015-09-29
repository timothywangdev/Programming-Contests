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

int n,m,a[1000001];
bool s[1001][1000];
bool vis[1001][1000];
int c=0;
bool search(int i,int mod){
  if(vis[i][mod])return s[i][mod];
  vis[i][mod]=true;
  c++;
  if(c>1000*1000){
    exit(-1);
  }
  if(i==1){
    s[i][mod]=(a[i]%m==mod);
  }
  else{
    int k=ceil((double)(a[i]-mod)/m);
    s[i][mod]=search(i-1,mod)||search(i-1,(mod-a[i]+k*m)%m)||(a[i]%m==mod);
  }
  return s[i][mod];
}

int main(){
  memset(s,false,sizeof(s));
  memset(vis,false,sizeof(vis));
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  if(n>m){
    cout<<"YES"<<endl;
  }
  else{
    if(search(n,0)){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
   return 0;
}

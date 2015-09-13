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

LL n,k;
LL fib[51];
int main(){
  fib[0]=0;
  fib[1]=1;
  for(int i=2;i<=50;i++){
    fib[i]=fib[i-1]+fib[i-2];
  }
  
  cin>>n>>k;
  bool first=true;
  int i=1;
  while(i<=n){
    if(k>fib[n-i+1]){
      if(!first)
	cout<<" "<<i+1<<" "<<i;
      else{
	first=false;
	cout<<i+1<<" "<<i;
      }
      k-=fib[n-i+1];
      i+=2;
    }
    else{
      if(!first){
	cout<<" "<<i;
      }
      else{
	first=false;
	cout<<i;
      }
      i++;
    }
  }
   return 0;
}

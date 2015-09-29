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

LL n,x;
int main(){
  cin>>n>>x;
  LL sum=0;
  LL m=sqrt(x);
  for(LL i=1;i<=m;i++){
    if(x%i==0){
      if(i>n||x/i>n)continue;
      sum+=2;
      if(x/i==i){
	sum--;
      }
    }
  }
  cout<<sum<<endl;
   return 0;
}


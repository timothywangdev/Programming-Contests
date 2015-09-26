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

LL n,a[100000];
int main(){
   cin>>n;
   F(i,n){
      cin>>a[i];
   }
   int len=1,rv=1;
   for(int i=1;i<n;i++){
      if(a[i]>=a[i-1]){
	 len++;
      }
      else{
	 len=1;
      }
      rv=max(rv,len);
   }
   cout<<rv<<endl;
   return 0;
}

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
int n,m;
char a[100000];
int main(){
   cin>>n>>m;
   F(i,n){
      cin>>a[i];
   }
   LL rv=n*m-n;
   for(int i=1;i<n;i++){
      if(a[i]!=a[i-1]){
	 rv+=n*m-n;
      }
   }
   LL c=1;
   for(int i=1;i<n;i++){
      if(c==1){
	 if(a[i]==a[i-1]){
	    continue;
	 }
	 else{
	    c++;
	 }
      }
      else{
	 if(a[i]==a[i-2]){
	    c++;
	 }
	 else{
	    rv-=(c*(c-1))/2;
	    if(a[i]==a[i-1]){
	       c=1;
	    }
	    else{
	       c=2;
	    }
	 }
      }
   }
   cout<<rv-(c*(c-1))/2<<endl;
   return 0;
}

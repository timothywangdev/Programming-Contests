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


int n;
LL a[1000000],f[1000000];
int last[1000000];
bool check(int i){
   return abs(a[i]-a[i-1])<=1;
}
int main(){
   cin>>n;
   F(i,n){
      cin>>a[i];
   }
   sort(a,a+n);
   int pre=-1;
   F(i,n){
      last[i]=pre;
      if(i>=1&&abs(a[i]-a[i-1])<=1){
	 pre=i;
      }
   }
   memset(f,0,sizeof(f));
   for(int i=1;i<=n;i++){
      if(i>=3){
	 if(check(i-1)){
	    int k=last[i-2];
	    if(k==-1){
	       f[i]=f[i-1];
	       continue;
	    }
	    f[i]=max(f[i-1],f[k-1]+a[i-2]*a[k-1]);
	 }
	 else{
	    f[i]=f[i-1];
	 }
      }
   }
   cout<<f[n]<<endl;
   return 0;
}

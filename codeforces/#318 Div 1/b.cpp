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


int a[100000],n,r[100000],l[100000];;
int main(){
   scanf("%d",&n);
   F(i,n){
      scanf("%d",&a[i]);
   }
   l[0]=1;
   for(int i=1;i<=n;i++){
      l[i]=min(l[i-1]+1,a[i]);
   }
   r[n-1]=1;
   for(int i=n-2;i>=0;i--){
      r[i]=min(r[i+1]+1,a[i]);
   }
   int rv=0;
   F(i,n){
      rv=max(rv,min(l[i],r[i]));
   }
   cout<<rv<<endl;
   return 0;
}

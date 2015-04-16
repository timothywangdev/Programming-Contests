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
LL A,a[200000];
int main(){
   cin>>n>>A;
   LL sum=0;
   F(i,n){
      cin>>a[i];
      sum+=a[i];
   }
   F(i,n){
      LL minimum=n-1!=0?max((LL)0,A-sum+a[i]):A;
      LL maximum=A-n+1;
      int rv=0;
      if(minimum>1){
	 rv+=minimum-1;
      }
      if(maximum<a[i]){
	 rv+=a[i]-maximum;
      }
      cout<<rv<<" ";
   }
   cout<<endl;
   return 0;
}
